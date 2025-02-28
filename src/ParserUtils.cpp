#include "JsonFieldDescription.h"
#include <ParserUtils.hpp>
#include <nlohmann/json.hpp>

namespace ParserUtils {
    FieldType getType(const nlohmann::json& json) {
        switch (json.type()) {
            case nlohmann::json::value_t::object:
                return FieldType::OBJECT;
            case nlohmann::json::value_t::array:
                return FieldType::ARRAY;
            case nlohmann::json::value_t::string:
                return FieldType::STRING;
            case nlohmann::json::value_t::number_integer:
                return FieldType::NUMBER;
            case nlohmann::json::value_t::number_float:
                return FieldType::NUMBER_FLOAT;
            case nlohmann::json::value_t::number_unsigned:
                return FieldType::UNSIGNED;
            case nlohmann::json::value_t::boolean:
                return FieldType::BOOLEAN; 
            default:
                return FieldType::NULL_;
        }
    }



    bool isEqualToDescription(const nlohmann::json& json,const std::string& field_name, const FieldDescription& description) {
        bool is_name_equal; 

        if (description.name == "Any") {
            is_name_equal = true;
        }else{
            is_name_equal = field_name == description.name;
        }

        FieldType field_type = getType(json);
        bool is_type_equal = field_type == description.type;
        return is_name_equal && is_type_equal;
           
    }

}
