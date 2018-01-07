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
int visit_field(
    const struct GraphQLAstField *field,
    void *user_data)
{
    graphql_compile_t *data = user_data;
    const struct GraphQLAstName *field_name_node = GraphQLAstField_get_name(field);
    const char *field_name = GraphQLAstName_get_value(field_name_node);

    graphql_field f = corto_create(NULL, NULL, graphql_field_o);
    corto_set_str(&f->name, field_name);

    graphql_field current_field = NULL;
    if (corto_ll_count(data->field_stack)) {
        current_field = corto_ll_get(data->field_stack, 0);
    }

    /* If this is the top-level field, append to query, otherwise to current field */
    if (!current_field) {
        graphql_fieldListAppend(data->query->fields, f);
    } else {
        graphql_fieldListAppend(current_field->fields, f);
    }

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

int cortomain(int argc, char *argv[]) {

    /* Insert implementation */

    return 0;
}
