#ifndef PARSERUTILS_HPP
#define PARSERUTILS_HPP

#include <JsonHandler.hpp>
#include <JsonSchema.h>
#include <InstructionSetDescription.h>
#include <nlohmann/json.hpp>


namespace ParserUtils {
    bool IsEqualToSchema(nlohmann::json json, JsonSchema schema);
};

#endif
