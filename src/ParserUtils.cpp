#include <JsonFieldDescription.h>
#include <ParserUtils.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <cassert>
#include <functional>

namespace ParserUtils {
    JsonSchema::FieldType getType(const nlohmann::json& json) {
        switch (json.type()) {
            case nlohmann::json::value_t::object:
                return JsonSchema::FieldType::OBJECT;
            case nlohmann::json::value_t::array:
                return JsonSchema::FieldType::ARRAY;
            case nlohmann::json::value_t::string:
                return JsonSchema::FieldType::STRING;
            case nlohmann::json::value_t::number_integer:
                return JsonSchema::FieldType::NUMBER;
            case nlohmann::json::value_t::number_float:
                return JsonSchema::FieldType::NUMBER_FLOAT;
            case nlohmann::json::value_t::number_unsigned:
                return JsonSchema::FieldType::UNSIGNED;
            case nlohmann::json::value_t::boolean:
                return JsonSchema::FieldType::BOOLEAN; 
            case nlohmann::json::value_t::null:
                return JsonSchema::FieldType::NULL_;
            default:
                std::cerr << "Invalid type" << std::endl;
                assert(false);
        }
    }

    std::string getFieldTypeName(const JsonSchema::FieldType& type) {
        switch (type) {
            case JsonSchema::FieldType::OBJECT:
                return "OBJECT";
            case JsonSchema::FieldType::ARRAY:
                return "ARRAY";
            case JsonSchema::FieldType::STRING:
                return "STRING";
            case JsonSchema::FieldType::NUMBER:
                return "NUMBER";
            case JsonSchema::FieldType::NUMBER_FLOAT:
                return "NUMBER_FLOAT";
            case JsonSchema::FieldType::UNSIGNED:
                return "UNSIGNED";
            case JsonSchema::FieldType::BOOLEAN:
                return "BOOLEAN";
            case JsonSchema::FieldType::NULL_:
                return "NULL_";
            default:
                std::cerr << "Invalid type" << std::endl;
                assert(false);
        }
    }

    bool isEqualToDescription(const nlohmann::json& json,const std::string& field_name, const JsonSchema::FieldDescription& description) {
        bool is_name_equal; 

        if (description.name == "Any") {
            is_name_equal = true;
        }else{
            is_name_equal = field_name == description.name;
        }

        JsonSchema::FieldType field_type = getType(json);
        bool is_type_equal = field_type == description.type;


        return is_name_equal && is_type_equal;
           
    }
    bool isConstraintNull(const JsonSchema::FieldConstraints &constraints_a, const JsonSchema::FieldConstraintsType &constraint_type){
        switch (constraint_type) {
            case JsonSchema::FieldConstraintsType::MIN_LENGTH:
                return constraints_a.minLength == nullptr;
            case JsonSchema::FieldConstraintsType::MAX_LENGTH:
                return constraints_a.maxLength == nullptr;
            case JsonSchema::FieldConstraintsType::MIN_VALUE:
                return constraints_a.minValue == nullptr;
            case JsonSchema::FieldConstraintsType::MAX_VALUE:
                return constraints_a.maxValue == nullptr;
            default:
                std::cerr << "Invalid constraint type" << std::endl;
                assert(false); 
        } 
    }

    bool areConstraintsEqual(const JsonSchema::FieldConstraints &constraints_a, const JsonSchema::FieldConstraints &constraints_b, const JsonSchema::FieldConstraintsType &constraint_type){
        switch (constraint_type) {
            case JsonSchema::FieldConstraintsType::MIN_LENGTH:
                return *constraints_a.minLength == *constraints_b.minLength;
            case JsonSchema::FieldConstraintsType::MAX_LENGTH:
                return *constraints_a.maxLength == *constraints_b.maxLength;
            case JsonSchema::FieldConstraintsType::MIN_VALUE:
                return *constraints_a.minValue == *constraints_b.minValue;
            case JsonSchema::FieldConstraintsType::MAX_VALUE:
                return *constraints_a.maxValue == *constraints_b.maxValue;
            default:
                std::cerr << "Invalid constraint type" << std::endl;
                assert(false);    
        }  
    }

    bool areAllConstraintsEqual(const JsonSchema::FieldConstraints &constraints_a, const JsonSchema::FieldConstraints &constraints_b){
        return false;
    } 
    bool areDescriptionsEqual(const JsonSchema::FieldDescription &description_a, const JsonSchema::FieldDescription &description_b){

        bool is_name_equal = description_a.name == description_b.name;
        bool is_type_equal = description_a.type == description_b.type;
        bool is_required_equal = description_a.isRequired == description_b.isRequired;
       

        return is_name_equal && is_type_equal && is_required_equal; 
    }
   

    const std::vector <std::reference_wrapper<JsonSchema::FieldDescription>> getSubJsonSchema(const JsonSchema::FieldDescription& main_field_description, const std::string& sub_field_name){
        std::vector<std::reference_wrapper<JsonSchema::FieldDescription>> sub_fields_found;
        for (auto sub_field = main_field_description.subFieldsFormats->begin(); sub_field != main_field_description.subFieldsFormats->end(); ++sub_field){
            if (sub_field->name == sub_field_name || sub_field->name == "Any"){
                sub_fields_found.push_back(*sub_field);
            }
        }
        return sub_fields_found; 
    }      
}
