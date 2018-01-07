/* This is a managed file. Do not delete this comment. */

#include <graphql/graphql.h>

typedef struct graphql_compile_t {
    graphql_query query;
    corto_ll field_stack;
    graphql_argument current_argument;
} graphql_compile_t;

static
int visit_int_value(
    const struct GraphQLAstIntValue *int_value,
    void *user_data)
{
    graphql_compile_t *data = user_data;

    graphql_valueAssign_m_int(
        &data->current_argument->value,
        Graphql_Int,
        GraphQLAstIntValue_get_value(int_value));

    return 1;
}

static
int visit_float_value(
    const struct GraphQLAstFloatValue *float_value,
    void *user_data)
{
    graphql_compile_t *data = user_data;

    graphql_valueAssign_m_float(
        &data->current_argument->value,
        Graphql_Float,
        GraphQLAstFloatValue_get_value(float_value));

    return 1;
}

static
int visit_string_value(
    const struct GraphQLAstStringValue *string_value,
    void *user_data)
{
    graphql_compile_t *data = user_data;

    graphql_valueAssign_m_string(
        &data->current_argument->value,
        Graphql_String,
        GraphQLAstStringValue_get_value(string_value));

    return 1;
}

static
int visit_boolean_value(
    const struct GraphQLAstBooleanValue *boolean_value,
    void *user_data)
{
    graphql_compile_t *data = user_data;

    graphql_valueAssign_m_bool(
        &data->current_argument->value,
        Graphql_Boolean,
        GraphQLAstBooleanValue_get_value(boolean_value));

    return 1;
}

static
int visit_null_value(
    const struct GraphQLAstNullValue *null_value,
    void *user_data)
{
    graphql_compile_t *data = user_data;

    graphql_valueAssign_m_string(
        &data->current_argument->value,
        Graphql_String,
        NULL);

    return 1;
}

static
int visit_argument(
    const struct GraphQLAstArgument *argument,
    void *user_data)
{
    graphql_compile_t *data = user_data;
    const struct GraphQLAstName *argument_node = GraphQLAstArgument_get_name(argument);
    const char *argument_name = GraphQLAstName_get_value(argument_node);

    graphql_argument a = corto_create(NULL, NULL, graphql_argument_o);
    corto_set_str(&a->name, argument_name);

    /* There should always be a field when parsing an argument */
    graphql_field current_field = corto_ll_get(data->field_stack, 0);
    graphql_argumentListAppend(current_field->arguments, a);
    data->current_argument = a;

    return 1;
}

static
void end_visit_argument(
    const struct GraphQLAstArgument *argument,
    void *user_data)
{
    graphql_compile_t *data = user_data;
    graphql_argument a = data->current_argument;
    graphql_field f = corto_ll_get(data->field_stack, 0);

    if (corto_instanceof(graphql_toplevel_field_o, f)) {
        graphql_toplevel_field tf = (graphql_toplevel_field)f;
        if (!strcmp(a->name, "select")) {
            if (a->value.d != Graphql_String) {
                corto_throw("expected 'select' argument to be of type string");
            } else {
                corto_set_str(&tf->query.select, a->value.is.m_string);
            }
        } else if (!strcmp(a->name, "from")) {
            if (a->value.d != Graphql_String) {
                corto_throw("expected 'from' argument to be of type string");
            } else {
                corto_set_str(&tf->query.from, a->value.is.m_string);
            }
        }
    }
}

static
int visit_field(
    const struct GraphQLAstField *field,
    void *user_data)
{
    graphql_compile_t *data = user_data;
    const struct GraphQLAstName *field_name_node = GraphQLAstField_get_name(field);
    const char *field_name = GraphQLAstName_get_value(field_name_node);

    graphql_field current_field = NULL;
    if (corto_ll_count(data->field_stack)) {
        current_field = corto_ll_get(data->field_stack, 0);
    }

    graphql_field f = NULL;

    /* If this is the top-level field, append to query, otherwise to current field */
    if (!current_field) {
        f = corto_create(NULL, NULL, graphql_toplevel_field_o);
        graphql_fieldListAppend(data->query->fields, f);
    } else {
        f = corto_create(NULL, NULL, graphql_field_o);
        graphql_fieldListAppend(current_field->fields, f);
    }

    corto_set_str(&f->name, field_name);

    /* Append field to field stack */
    corto_ll_insert(data->field_stack, f);
    return 1;
}

static
void end_visit_field(
    const struct GraphQLAstField *field,
    void *user_data)
{
    graphql_compile_t *data = user_data;

    /* Take field from stack */
    corto_ll_takeFirst(data->field_stack);
}

struct GraphQLAstVisitorCallbacks compiler_visitor = {
    .visit_field = visit_field,
    .end_visit_field = end_visit_field,
    .visit_argument = visit_argument,
    .end_visit_argument = end_visit_argument,
    .visit_int_value = visit_int_value,
    .visit_float_value = visit_float_value,
    .visit_string_value = visit_string_value,
    .visit_boolean_value = visit_boolean_value,
    .visit_null_value = visit_null_value
};
graphql_query graphql_compile(
    const char *query)
{
    const char *error = NULL;
    struct GraphQLAstNode *node = graphql_parse_string(query, &error);
    if (!node) {
        corto_throw(error);
        graphql_error_free(error);
        goto error;
    }

    graphql_compile_t walkData = {
        .query = corto_create(NULL, NULL, graphql_query_o),
        .field_stack = corto_ll_new()
    };
    graphql_node_visit(node, &compiler_visitor, &walkData);
    corto_log("%s\n", corto_serialize_value(walkData.query, "text/json"));
    return walkData.query;
error:
    return NULL;
}

static
int16_t graphql_eval_fields(
    graphql_field field,
    corto_result *r,
    corto_type type,
    void *ptr,
    corto_buffer *result)
{
    if (field->fields) {
        corto_buffer_appendstr(result, "{");

        corto_iter it = corto_ll_iter(field->fields);
        int count = 0;
        while (corto_iter_hasNext(&it)) {
            graphql_field f = corto_iter_next(&it);
            if (count) {
                corto_buffer_appendstr(result, ",");
            }
            count ++;

            if (f->name[0] == '_') {
                char *value = NULL;

                /* Meta member */
                if (!strcmp(f->name, "_id")) {
                    value = r->id;
                } else if (!strcmp(f->name, "_parent")) {
                    value = r->parent;
                } else if (!strcmp(f->name, "_type")) {
                    value = r->type;
                }

                corto_buffer_append(result, "\"%s\":\"%s\"", f->name, value);

            } else if (islower(f->name[0])) {
                /* Find member in type */
                corto_member m = corto_interface_resolveMember(type, f->name);
                if (!m) {
                    corto_throw("cannot find member '%s' in type '%s'",
                        f->name, corto_fullpath(NULL, type));
                    goto error;
                }

                /* Cast value in pointer to string */
                char *str = NULL;
                if (corto_ptr_cast(m->type, ptr, corto_string_o, &str)) {
                    corto_throw("cast from '%s' to string failed for member '%s'",
                        corto_fullpath(NULL, m->type),
                        corto_fullpath(NULL, m));
                    goto error;
                }

                /* Append member to JSON */
                corto_buffer_append(result, "\"%s\":%s", corto_idof(m), str);

                /* Free resources */
                if (str) free(str);

            } else if (isupper(f->name[0])) {
                /* Resolve nested object */
            }
        }
        corto_buffer_appendstr(result, "}");
    }

    return 0;
error:
    return -1;
}

static
int16_t graphql_eval_toplevelField(
    graphql_toplevel_field field,
    corto_buffer *result)
{
    const char *select = field->query.select;
    const char *from = field->query.from;

    if (!select) select = "*";
    if (!from) from = "/";

    corto_iter it;
    if (corto_select(select).from(from).contentType("binary/corto").iter(&it)) {
        corto_throw(NULL);
        goto error;
    }

    corto_buffer_append(result, "{\"%s\":[", ((graphql_field)field)->name);

    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        corto_type t = corto_resolve(NULL, r->type);
        if (graphql_eval_fields((graphql_field)field, r, t, (void*)r->value, result)) {
            goto error;
        }
    }

    corto_buffer_append(result, "]}");

    return 0;
error:
    return -1;
}

corto_string graphql_eval(
    graphql_query query)
{
    corto_buffer result = CORTO_BUFFER_INIT;

    corto_buffer_appendstr(&result, "{\"data\":");

    /* Evaluate top-level treeql queries */
    corto_iter it = corto_ll_iter(query->fields);
    while (corto_iter_hasNext(&it)) {
        graphql_field f = corto_iter_next(&it);
        if (graphql_eval_toplevelField((graphql_toplevel_field)f, &result)) {
            goto error;
        }
    }

    corto_buffer_appendstr(&result, "}");

    return corto_buffer_str(&result);
error:
    return NULL;
}

int cortomain(int argc, char *argv[]) {

    /* Insert implementation */

    return 0;
}
