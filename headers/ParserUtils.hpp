#ifndef PARSERUTILS_HPP
#define PARSERUTILS_HPP

#include <JsonFieldDescription.h>
#include <JsonHandler.hpp>
#include <JsonSchema.h>
#include <InstructionSetDescription.h>
#include <nlohmann/json.hpp>
#include <functional>

namespace ParserUtils {
    bool isEqualToDescription(const nlohmann::json& json, const std::string& field_name, const FieldDescription& description);
    bool isConstraintNull(const FieldConstraints& constraints, const FieldConstraintsType& constraint_type);
    bool areConstraintsEqual(const FieldConstraints &constraints_a, const FieldConstraints &constraints_b, const FieldConstraintsType &constraint_type);
    bool areAllConstraintsEqual(const FieldConstraints& constraints_a, const FieldConstraints& constraints_b);
    bool areDescriptionsEqual(const FieldDescription& description_a, const FieldDescription& description_b);
    FieldType getType(const nlohmann::json& json); 
    const std::vector<std::reference_wrapper<FieldDescription>> getSubFieldDescription(const FieldDescription& main_field_description, const std::string& sub_field_name);
};

#endif
