#include <JsonFieldDescription.h>
#include <ParserUtils.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <cassert>
#include <functional>

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
        std::cout << (unsigned)field_type << " " << (unsigned) description.type << std::endl;
        return is_name_equal && is_type_equal;
           
    }
    bool isConstraintNull(const FieldConstraints &constraints_a, const FieldConstraintsType &constraint_type){
        switch (constraint_type) {
            case FieldConstraintsType::MIN_LENGTH:
                return constraints_a.minLength == nullptr;
            case FieldConstraintsType::MAX_LENGTH:
                return constraints_a.maxLength == nullptr;
            case FieldConstraintsType::MIN_VALUE:
                return constraints_a.minValue == nullptr;
            case FieldConstraintsType::MAX_VALUE:
                return constraints_a.maxValue == nullptr;
            default:
                std::cerr << "Invalid constraint type" << std::endl;
                assert(false); 
        } 
    }

    bool areConstraintsEqual(const FieldConstraints &constraints_a, const FieldConstraints &constraints_b, const FieldConstraintsType &constraint_type){
        switch (constraint_type) {
            case FieldConstraintsType::MIN_LENGTH:
                return *constraints_a.minLength == *constraints_b.minLength;
            case FieldConstraintsType::MAX_LENGTH:
                return *constraints_a.maxLength == *constraints_b.maxLength;
            case FieldConstraintsType::MIN_VALUE:
                return *constraints_a.minValue == *constraints_b.minValue;
            case FieldConstraintsType::MAX_VALUE:
                return *constraints_a.maxValue == *constraints_b.maxValue;
            default:
                std::cerr << "Invalid constraint type" << std::endl;
                assert(false);    
        }  
    }

    bool areAllConstraintsEqual(const FieldConstraints &constraints_a, const FieldConstraints &constraints_b){
        return false;
    } 
    bool areDescriptionsEqual(const FieldDescription &description_a, const FieldDescription &description_b){

        bool is_name_equal = description_a.name == description_b.name;
        bool is_type_equal = description_a.type == description_b.type;
        bool is_required_equal = description_a.isRequired == description_b.isRequired;
        bool is_constraints_min_length_equal = *description_a.constraints.minLength == *description_b.constraints.minLength;   
        bool is_constraints_max_length_equal = *description_a.constraints.maxLength == *description_b.constraints.maxLength;   
        bool is_constraints_min_value_equal = *description_a.constraints.minValue == *description_b.constraints.minValue;   
        bool is_constraints_max_value_equal = *description_a.constraints.maxValue == *description_b.constraints.maxValue;

        return false; 
    }
   

    const std::vector <std::reference_wrapper<FieldDescription>> getSubFieldDescription(const FieldDescription& main_field_description, const std::string& field_name){

        std::vector<std::reference_wrapper<FieldDescription>> sub_fields_found;
        for (auto sub_field = main_field_description.subFieldsFormats->begin(); sub_field != main_field_description.subFieldsFormats->end(); ++sub_field){
            if (sub_field->name == field_name || field_name == "Any"){
                sub_fields_found.push_back(*sub_field);
            }
            std::cout << "sub_field" << sub_field->name << std::endl;
        }
        return sub_fields_found; 
    }      
}
