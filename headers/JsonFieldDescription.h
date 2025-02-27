#ifndef FIELDDESCRIPTION_H
#define FIELDDESCRIPTION_H

#include <string>
#include <vector>
#include <memory>


enum class FieldType {
    String,
    Number,
    Unsigned,
    Boolean,
    Object,
    Array,
    Null
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
