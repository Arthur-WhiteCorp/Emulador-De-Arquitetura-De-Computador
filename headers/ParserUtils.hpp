#ifndef PARSERUTILS_HPP
#define PARSERUTILS_HPP

#include "JsonFieldDescription.h"
#include <JsonHandler.hpp>
#include <JsonSchema.h>
#include <InstructionSetDescription.h>
#include <nlohmann/json.hpp>


namespace ParserUtils {
    bool isEqualToDescription(const nlohmann::json& json, const std::string& field_name, const FieldDescription& description);
    FieldType getType(const nlohmann::json& json); 
};

#endif
