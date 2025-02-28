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

struct FieldConstraints {
    std::unique_ptr<size_t> minLength;
    std::unique_ptr<size_t> maxLength;
    std::unique_ptr<size_t> minValue;
    std::unique_ptr<size_t> maxValue;
};

struct FieldDescription {
    std::string name;
    FieldType type;
    bool isRequired;
    FieldConstraints constraints;
    std::unique_ptr<std::vector<FieldDescription>> subFieldsFormats; // descreve os formatos dos campos aninhados
};

#endif
