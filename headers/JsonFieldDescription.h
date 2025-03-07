#ifndef FIELD_DESCRIPTION_H
#define FIELD_DESCRIPTION_H

#include <string>
#include <vector>
#include <memory>

namespace JsonSchema{

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
        std::shared_ptr<FieldDescription> parent_field;
        std::string name;
        FieldType type;
        bool is_required;
        std::shared_ptr<std::vector<FieldDescription>> sub_fields_formats; // descreve os formatos dos campos aninhados
        FieldDescription(): parent_field(nullptr), name(""), type(FieldType::NULL_), is_required(false), sub_fields_formats(nullptr) {};  
        FieldDescription(std::string name, FieldType type, bool is_required ): name(name), type(type), is_required(is_required), sub_fields_formats() {}
    };

    const FieldDescription null_description = FieldDescription("null", FieldType::NULL_, false);
    const std::string ANY = "Any"; // campo de nome qualquer
}
#endif
