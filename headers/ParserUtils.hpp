#ifndef PARSERUTILS_HPP
#define PARSERUTILS_HPP

#include <JsonFieldDescription.h>
#include <JsonHandler.hpp>
#include <JsonSchema.h>
#include <InstructionSetDescription.h>
#include <nlohmann/json.hpp>
#include <functional>

namespace ParserUtils {
    bool isEqualToDescription(const nlohmann::json& json, const std::string& field_name, const JsonSchema::FieldDescription& description);
    bool isConstraintNull(const JsonSchema::FieldConstraints& constraints, const JsonSchema::FieldConstraintsType& constraint_type);
    bool areConstraintsEqual(const JsonSchema::FieldConstraints &constraints_a, const JsonSchema::FieldConstraints &constraints_b, const JsonSchema::FieldConstraintsType &constraint_type);
    bool areAllConstraintsEqual(const JsonSchema::FieldConstraints& constraints_a, const JsonSchema::FieldConstraints& constraints_b);
    bool areDescriptionsEqual(const JsonSchema::FieldDescription& description_a, const JsonSchema::FieldDescription& description_b);
    JsonSchema::FieldType getType(const nlohmann::json& json); 
    std::string getFieldTypeName(const JsonSchema::FieldType& type); // pega o nome do tipo (string ao inves de unsigned)
    const std::vector<std::reference_wrapper<JsonSchema::FieldDescription>> getSubJsonSchema(const JsonSchema::FieldDescription& main_field_description, const std::string& sub_field_name);
    void addSubFieldDescription(JsonSchema::FieldDescription& main_field_description, const std::string& sub_field_name, const JsonSchema::FieldType& sub_field_type, const bool& is_required);

};

#endif
