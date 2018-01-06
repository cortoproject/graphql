
#include <graphql/query/query.h>

static
int visit_document(
    const struct GraphQLAstDocument *document,
    void *user_data)
{
    printf("visit_Document\n");
    return 1;
}

static
void end_visit_document(
    const struct GraphQLAstDocument *document,
    void *user_data)
{
    printf("end_visit_Document\n");
}

static
int visit_operation_definition(
    const struct GraphQLAstOperationDefinition *operation_definition,
    void *user_data)
{
    printf("visit_OperationDefinition\n");
    return 1;
}

static
void end_visit_operation_definition(
    const struct GraphQLAstOperationDefinition *operation_definition,
    void *user_data)
{
    printf("end_visit_OperationDefinition\n");
}

static
int visit_variable_definition(
    const struct GraphQLAstVariableDefinition *variable_definition,
    void *user_data)
{
    printf("visit_VariableDefinition\n");
    return 1;
}

static
void end_visit_variable_definition(
    const struct GraphQLAstVariableDefinition *variable_definition,
    void *user_data)
{
    printf("end_visit_VariableDefinition\n");
}

static
int visit_selection_set(
    const struct GraphQLAstSelectionSet *selection_set,
    void *user_data)
{
    printf("visit_SelectionSet\n");
    return 1;
}

static
void end_visit_selection_set(
    const struct GraphQLAstSelectionSet *selection_set,
    void *user_data)
{
    printf("end_visit_SelectionSet\n");
}

static
int visit_field(
    const struct GraphQLAstField *field,
    void *user_data)
{
    printf("visit_Field\n");
    return 1;
}

static
void end_visit_field(
    const struct GraphQLAstField *field,
    void *user_data)
{
    printf("end_visit_Field\n");
}

static
int visit_argument(
    const struct GraphQLAstArgument *argument,
    void *user_data)
{
    printf("visit_Argument\n");
    return 1;
}

static
void end_visit_argument(
    const struct GraphQLAstArgument *argument,
    void *user_data)
{
    printf("end_visit_Argument\n");
}

static
int visit_fragment_spread(
    const struct GraphQLAstFragmentSpread *fragment_spread,
    void *user_data)
{
    printf("visit_FragmentSpread\n");
    return 1;
}

static
void end_visit_fragment_spread(
    const struct GraphQLAstFragmentSpread *fragment_spread,
    void *user_data)
{
    printf("end_visit_FragmentSpread\n");
}

static
int visit_inline_fragment(
    const struct GraphQLAstInlineFragment *inline_fragment,
    void *user_data)
{
    printf("visit_InlineFragment\n");
    return 1;
}

static
void end_visit_inline_fragment(
    const struct GraphQLAstInlineFragment *inline_fragment,
    void *user_data)
{
    printf("end_visit_InlineFragment\n");
}

static
int visit_fragment_definition(
    const struct GraphQLAstFragmentDefinition *fragment_definition,
    void *user_data)
{
    printf("visit_FragmentDefinition\n");
    return 1;
}

static
void end_visit_fragment_definition(
    const struct GraphQLAstFragmentDefinition *fragment_definition,
    void *user_data)
{
    printf("end_visit_FragmentDefinition\n");
}

static
int visit_variable(
    const struct GraphQLAstVariable *variable,
    void *user_data)
{
    printf("visit_Variable\n");
    return 1;
}

static
void end_visit_variable(
    const struct GraphQLAstVariable *variable,
    void *user_data)
{
    printf("end_visit_Variable\n");
}

static
int visit_int_value(
    const struct GraphQLAstIntValue *int_value,
    void *user_data)
{
    printf("visit_IntValue\n");
    return 1;
}

static
void end_visit_int_value(
    const struct GraphQLAstIntValue *int_value,
    void *user_data)
{
    printf("end_visit_IntValue\n");
}

static
int visit_float_value(
    const struct GraphQLAstFloatValue *float_value,
    void *user_data)
{
    printf("visit_FloatValue\n");
    return 1;
}

static
void end_visit_float_value(
    const struct GraphQLAstFloatValue *float_value,
    void *user_data)
{
    printf("end_visit_FloatValue\n");
}

static
int visit_string_value(
    const struct GraphQLAstStringValue *string_value,
    void *user_data)
{
    printf("visit_StringValue\n");
    return 1;
}

static
void end_visit_string_value(
    const struct GraphQLAstStringValue *string_value,
    void *user_data)
{
    printf("end_visit_StringValue\n");
}

static
int visit_boolean_value(
    const struct GraphQLAstBooleanValue *boolean_value,
    void *user_data)
{
    printf("visit_BooleanValue\n");
    return 1;
}

static
void end_visit_boolean_value(
    const struct GraphQLAstBooleanValue *boolean_value,
    void *user_data)
{
    printf("end_visit_BooleanValue\n");
}

static
int visit_null_value(
    const struct GraphQLAstNullValue *null_value,
    void *user_data)
{
    printf("visit_NullValue\n");
    return 1;
}

static
void end_visit_null_value(
    const struct GraphQLAstNullValue *null_value,
    void *user_data)
{
    printf("end_visit_NullValue\n");
}

static
int visit_enum_value(
    const struct GraphQLAstEnumValue *enum_value,
    void *user_data)
{
    printf("visit_EnumValue\n");
    return 1;
}

static
void end_visit_enum_value(
    const struct GraphQLAstEnumValue *enum_value,
    void *user_data)
{
    printf("end_visit_EnumValue\n");
}

static
int visit_list_value(
    const struct GraphQLAstListValue *list_value,
    void *user_data)
{
    printf("visit_ListValue\n");
    return 1;
}

static
void end_visit_list_value(
    const struct GraphQLAstListValue *list_value,
    void *user_data)
{
    printf("end_visit_ListValue\n");
}

static
int visit_object_value(
    const struct GraphQLAstObjectValue *object_value,
    void *user_data)
{
    printf("visit_ObjectValue\n");
    return 1;
}

static
void end_visit_object_value(
    const struct GraphQLAstObjectValue *object_value,
    void *user_data)
{
    printf("end_visit_ObjectValue\n");
}

static
int visit_object_field(
    const struct GraphQLAstObjectField *object_field,
    void *user_data)
{
    printf("visit_ObjectField\n");
    return 1;
}

static
void end_visit_object_field(
    const struct GraphQLAstObjectField *object_field,
    void *user_data)
{
    printf("end_visit_ObjectField\n");
}

static
int visit_directive(
    const struct GraphQLAstDirective *directive,
    void *user_data)
{
    printf("visit_Directive\n");
    return 1;
}

static
void end_visit_directive(
    const struct GraphQLAstDirective *directive,
    void *user_data)
{
    printf("end_visit_Directive\n");
}

static
int visit_named_type(
    const struct GraphQLAstNamedType *named_type,
    void *user_data)
{
    printf("visit_NamedType\n");
    return 1;
}

static
void end_visit_named_type(
    const struct GraphQLAstNamedType *named_type,
    void *user_data)
{
    printf("end_visit_NamedType\n");
}

static
int visit_list_type(
    const struct GraphQLAstListType *list_type,
    void *user_data)
{
    printf("visit_ListType\n");
    return 1;
}

static
void end_visit_list_type(
    const struct GraphQLAstListType *list_type,
    void *user_data)
{
    printf("end_visit_ListType\n");
}

static
int visit_non_null_type(
    const struct GraphQLAstNonNullType *non_null_type,
    void *user_data)
{
    printf("visit_NonNullType\n");
    return 1;
}

static
void end_visit_non_null_type(
    const struct GraphQLAstNonNullType *non_null_type,
    void *user_data)
{
    printf("end_visit_NonNullType\n");
}

static
int visit_name(
    const struct GraphQLAstName *name,
    void *user_data)
{
    printf("visit_Name\n");
    return 1;
}

static
void end_visit_name(
    const struct GraphQLAstName *name,
    void *user_data)
{
    printf("end_visit_Name\n");
}

static
int visit_schema_definition(
    const struct GraphQLAstSchemaDefinition *schema_definition,
    void *user_data)
{
    printf("visit_SchemaDefinition\n");
    return 1;
}

static
void end_visit_schema_definition(
    const struct GraphQLAstSchemaDefinition *schema_definition,
    void *user_data)
{
    printf("end_visit_SchemaDefinition\n");
}

static
int visit_operation_type_definition(
    const struct GraphQLAstOperationTypeDefinition *operation_type_definition,
    void *user_data)
{
    printf("visit_OperationTypeDefinition\n");
    return 1;
}

static
void end_visit_operation_type_definition(
    const struct GraphQLAstOperationTypeDefinition *operation_type_definition,
    void *user_data)
{
    printf("end_visit_OperationTypeDefinition\n");
}

static
int visit_scalar_type_definition(
    const struct GraphQLAstScalarTypeDefinition *scalar_type_definition,
    void *user_data)
{
    printf("visit_ScalarTypeDefinition\n");
    return 1;
}

static
void end_visit_scalar_type_definition(
    const struct GraphQLAstScalarTypeDefinition *scalar_type_definition,
    void *user_data)
{
    printf("end_visit_ScalarTypeDefinition\n");
}

static
int visit_object_type_definition(
    const struct GraphQLAstObjectTypeDefinition *object_type_definition,
    void *user_data)
{
    printf("visit_ObjectTypeDefinition\n");
    return 1;
}

static
void end_visit_object_type_definition(
    const struct GraphQLAstObjectTypeDefinition *object_type_definition,
    void *user_data)
{
    printf("end_visit_ObjectTypeDefinition\n");
}

static
int visit_field_definition(
    const struct GraphQLAstFieldDefinition *field_definition,
    void *user_data)
{
    printf("visit_FieldDefinition\n");
    return 1;
}

static
void end_visit_field_definition(
    const struct GraphQLAstFieldDefinition *field_definition,
    void *user_data)
{
    printf("end_visit_FieldDefinition\n");
}

static
int visit_input_value_definition(
    const struct GraphQLAstInputValueDefinition *input_value_definition,
    void *user_data)
{
    printf("visit_InputValueDefinition\n");
    return 1;
}

static
void end_visit_input_value_definition(
    const struct GraphQLAstInputValueDefinition *input_value_definition,
    void *user_data)
{
    printf("end_visit_InputValueDefinition\n");
}

static
int visit_interface_type_definition(
    const struct GraphQLAstInterfaceTypeDefinition *interface_type_definition,
    void *user_data)
{
    printf("visit_InterfaceTypeDefinition\n");
    return 1;
}

static
void end_visit_interface_type_definition(
    const struct GraphQLAstInterfaceTypeDefinition *interface_type_definition,
    void *user_data)
{
    printf("end_visit_InterfaceTypeDefinition\n");
}

static
int visit_union_type_definition(
    const struct GraphQLAstUnionTypeDefinition *union_type_definition,
    void *user_data)
{
    printf("visit_UnionTypeDefinition\n");
    return 1;
}

static
void end_visit_union_type_definition(
    const struct GraphQLAstUnionTypeDefinition *union_type_definition,
    void *user_data)
{
    printf("end_visit_UnionTypeDefinition\n");
}

static
int visit_enum_type_definition(
    const struct GraphQLAstEnumTypeDefinition *enum_type_definition,
    void *user_data)
{
    printf("visit_EnumTypeDefinition\n");
    return 1;
}

static
void end_visit_enum_type_definition(
    const struct GraphQLAstEnumTypeDefinition *enum_type_definition,
    void *user_data)
{
    printf("end_visit_EnumTypeDefinition\n");
}

static
int visit_enum_value_definition(
    const struct GraphQLAstEnumValueDefinition *enum_value_definition,
    void *user_data)
{
    printf("visit_EnumValueDefinition\n");
    return 1;
}

static
void end_visit_enum_value_definition(
    const struct GraphQLAstEnumValueDefinition *enum_value_definition,
    void *user_data)
{
    printf("end_visit_EnumValueDefinition\n");
}

static
int visit_input_object_type_definition(
    const struct GraphQLAstInputObjectTypeDefinition *input_object_type_definition,
    void *user_data)
{
    printf("visit_InputObjectTypeDefinition\n");
    return 1;
}

static
void end_visit_input_object_type_definition(
    const struct GraphQLAstInputObjectTypeDefinition *input_object_type_definition,
    void *user_data)
{
    printf("end_visit_InputObjectTypeDefinition\n");
}

static
int visit_type_extension_definition(
    const struct GraphQLAstTypeExtensionDefinition *type_extension_definition,
    void *user_data)
{
    printf("visit_TypeExtensionDefinition\n");
    return 1;
}

static
void end_visit_type_extension_definition(
    const struct GraphQLAstTypeExtensionDefinition *type_extension_definition,
    void *user_data)
{
    printf("end_visit_TypeExtensionDefinition\n");
}

static
int visit_directive_definition(
    const struct GraphQLAstDirectiveDefinition *directive_definition,
    void *user_data)
{
    printf("visit_DirectiveDefinition\n");
    return 1;
}

static
void end_visit_directive_definition(
    const struct GraphQLAstDirectiveDefinition *directive_definition,
    void *user_data)
{
    printf("end_visit_DirectiveDefinition\n");
}

struct GraphQLAstVisitorCallbacks visitall_cb = {
    .visit_document = visit_document,
    .end_visit_document = end_visit_document,
    .visit_operation_definition = visit_operation_definition,
    .end_visit_operation_definition = end_visit_operation_definition,
    .visit_variable_definition = visit_variable_definition,
    .end_visit_variable_definition = end_visit_variable_definition,
    .visit_selection_set = visit_selection_set,
    .end_visit_selection_set = end_visit_selection_set,
    .visit_field = visit_field,
    .end_visit_field = end_visit_field,
    .visit_argument = visit_argument,
    .end_visit_argument = end_visit_argument,
    .visit_fragment_spread = visit_fragment_spread,
    .end_visit_fragment_spread = end_visit_fragment_spread,
    .visit_inline_fragment = visit_inline_fragment,
    .end_visit_inline_fragment = end_visit_inline_fragment,
    .visit_fragment_definition = visit_fragment_definition,
    .end_visit_fragment_definition = end_visit_fragment_definition,
    .visit_variable = visit_variable,
    .end_visit_variable = end_visit_variable,
    .visit_int_value = visit_int_value,
    .end_visit_int_value = end_visit_int_value,
    .visit_float_value = visit_float_value,
    .end_visit_float_value = end_visit_float_value,
    .visit_string_value = visit_string_value,
    .end_visit_string_value = end_visit_string_value,
    .visit_boolean_value = visit_boolean_value,
    .end_visit_boolean_value = end_visit_boolean_value,
    .visit_null_value = visit_null_value,
    .end_visit_null_value = end_visit_null_value,
    .visit_enum_value = visit_enum_value,
    .end_visit_enum_value = end_visit_enum_value,
    .visit_list_value = visit_list_value,
    .end_visit_list_value = end_visit_list_value,
    .visit_object_value = visit_object_value,
    .end_visit_object_value = end_visit_object_value,
    .visit_object_field = visit_object_field,
    .end_visit_object_field = end_visit_object_field,
    .visit_directive = visit_directive,
    .end_visit_directive = end_visit_directive,
    .visit_named_type = visit_named_type,
    .end_visit_named_type = end_visit_named_type,
    .visit_list_type = visit_list_type,
    .end_visit_list_type = end_visit_list_type,
    .visit_non_null_type = visit_non_null_type,
    .end_visit_non_null_type = end_visit_non_null_type,
    .visit_name = visit_name,
    .end_visit_name = end_visit_name,
    .visit_schema_definition = visit_schema_definition,
    .end_visit_schema_definition = end_visit_schema_definition,
    .visit_operation_type_definition = visit_operation_type_definition,
    .end_visit_operation_type_definition = end_visit_operation_type_definition,
    .visit_scalar_type_definition = visit_scalar_type_definition,
    .end_visit_scalar_type_definition = end_visit_scalar_type_definition,
    .visit_object_type_definition = visit_object_type_definition,
    .end_visit_object_type_definition = end_visit_object_type_definition,
    .visit_field_definition = visit_field_definition,
    .end_visit_field_definition = end_visit_field_definition,
    .visit_input_value_definition = visit_input_value_definition,
    .end_visit_input_value_definition = end_visit_input_value_definition,
    .visit_interface_type_definition = visit_interface_type_definition,
    .end_visit_interface_type_definition = end_visit_interface_type_definition,
    .visit_union_type_definition = visit_union_type_definition,
    .end_visit_union_type_definition = end_visit_union_type_definition,
    .visit_enum_type_definition = visit_enum_type_definition,
    .end_visit_enum_type_definition = end_visit_enum_type_definition,
    .visit_enum_value_definition = visit_enum_value_definition,
    .end_visit_enum_value_definition = end_visit_enum_value_definition,
    .visit_input_object_type_definition = visit_input_object_type_definition,
    .end_visit_input_object_type_definition = end_visit_input_object_type_definition,
    .visit_type_extension_definition = visit_type_extension_definition,
    .end_visit_type_extension_definition = end_visit_type_extension_definition,
    .visit_directive_definition = visit_directive_definition,
    .end_visit_directive_definition = end_visit_directive_definition
};


int16_t graphql_query(
    const char *query)
{
    const char *error = NULL;
    struct GraphQLAstNode *node = graphql_parse_string(query, &error);
    if (!node) {
        corto_throw(error);
        graphql_error_free(error);
        goto error;
    }

    graphql_node_visit(node, &visitall_cb, NULL);

    return 0;
error:
    return -1;
}


int cortomain(int argc, char *argv[]) {

    return 0;
}
