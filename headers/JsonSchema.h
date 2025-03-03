#ifndef JSONSCHEMA_H
#define JSONSCHEMA_H

#include <JsonFieldDescription.h>
#include <unordered_map>
namespace JsonSchema {
    using JsonSchema = std::unordered_map<std::string, FieldDescription>;
}

#endif
