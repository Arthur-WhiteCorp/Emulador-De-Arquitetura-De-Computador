#ifndef FIELD_DESCRIPTION_H
#define FIELD_DESCRIPTION_H

#include <string>
#include <vector>
#include <memory>


enum class FieldType {
    STRING,
    NUMBER,
    NUMBER_FLOAT,
    UNSIGNED,
    BOOLEAN,
    OBJECT,
    ARRAY,
    NULL_
};

enum class FieldConstraintsType {
    MIN_LENGTH,
    MAX_LENGTH,
    MIN_VALUE,
    MAX_VALUE
};

struct FieldConstraints {
    std::unique_ptr<size_t> minLength; // MIN_LENGTH
    std::unique_ptr<size_t> maxLength; // MAX_LENGTH
    std::unique_ptr<size_t> minValue; // MIN_VALUE
    std::unique_ptr<size_t> maxValue; // MAX_VALUE
    FieldConstraints(): minLength(nullptr), maxLength(nullptr), minValue(nullptr), maxValue(nullptr) {}
};

struct FieldDescription {
    std::string name;
    FieldType type;
    bool isRequired;
    FieldConstraints constraints;
    std::unique_ptr<std::vector<FieldDescription>> subFieldsFormats; // descreve os formatos dos campos aninhados
    FieldDescription() = default;
    FieldDescription(std::string name, FieldType type, bool isRequired )
        : name(name), type(type), isRequired(isRequired), constraints(), subFieldsFormats() {}
};

const FieldDescription null_description = FieldDescription("null", FieldType::NULL_, false);
#endif
