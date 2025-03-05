#include "JsonFieldDescription.h"
#include <InstructionSetDescriptionParser.hpp>
#include <JsonSchema.h>
#include <memory>
#include <ParserUtils.hpp>
#include <set>

InstructionSetDescriptionParser::InstructionSetDescriptionParser(std::string file_path): handler(file_path) {
    initializeErrorFlags();
    if (handler.isValidJson()){
        machine_description_json = handler.getJson();
        putMainFieldsInSchema();
        parseInstructionSetDescription();
    }
}
InstructionSetDescriptionParser::~InstructionSetDescriptionParser() {
    
}
 
void InstructionSetDescriptionParser::initializeErrorFlags() {
    success_parsing = true;    
}
void InstructionSetDescriptionParser::putMainFieldsInSchema() {
    json_schema["Arithmetic_Logic"] = JsonSchema::FieldDescription();
    json_schema["Jumper"] = JsonSchema::FieldDescription();
    json_schema["Conditional_Jumper"] = JsonSchema::FieldDescription();
    json_schema["Data"] = JsonSchema::FieldDescription();

    initializeJsonSchema();
}

void InstructionSetDescriptionParser::initializeArithmeticLogicFieldSchema() {
    json_schema["Arithmetic_Logic"].name = "Arithmetic_Logic";
    json_schema["Arithmetic_Logic"].type = JsonSchema::FieldType::OBJECT;
    json_schema["Arithmetic_Logic"].is_required = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Arithmetic_Logic"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Arithmetic_Logic"].subFieldsFormats->at(0); 

    // Campo syntax
    ParserUtils::addSubFieldDescription(any_field, "syntax", JsonSchema::FieldType::STRING, true);

    // Campo behavior
    ParserUtils::addSubFieldDescription(any_field, "behavior", JsonSchema::FieldType::STRING, true); 
     
    // Campo number_of_args
    ParserUtils::addSubFieldDescription(any_field, "number_of_args", JsonSchema::FieldType::UNSIGNED, true);

    // Campo flags_modification
    ParserUtils::addSubFieldDescription(any_field, "flags_modification", JsonSchema::FieldType::STRING, true);
}
void InstructionSetDescriptionParser::initializeJumperFieldSchema() {
    json_schema["Jumper"].name = "Jumper";
    json_schema["Jumper"].type = JsonSchema::FieldType::OBJECT;
    json_schema["Jumper"].is_required = true;
    json_schema["Jumper"].subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Jumper"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Jumper"].subFieldsFormats->at(0); 

    // Campo syntax
    ParserUtils::addSubFieldDescription(any_field, "syntax", JsonSchema::FieldType::STRING, true);

    // Campo behavior
    ParserUtils::addSubFieldDescription(any_field, "behavior", JsonSchema::FieldType::STRING, true); 
     
    // Campo number_of_args
    ParserUtils::addSubFieldDescription(any_field, "number_of_args", JsonSchema::FieldType::UNSIGNED, true);
} 
void InstructionSetDescriptionParser::initializeConditionalJumperFieldSchema() {
    json_schema["Conditional_Jumper"].name = "Conditional_Jumper";
    json_schema["Conditional_Jumper"].type = JsonSchema::FieldType::OBJECT;
    json_schema["Conditional_Jumper"].is_required = true;
    json_schema["Conditional_Jumper"].subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Conditional_Jumper"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Conditional_Jumper"].subFieldsFormats->at(0); 

    // Campo syntax
    ParserUtils::addSubFieldDescription(any_field, "syntax", JsonSchema::FieldType::STRING, true);

    // Campo behavior
    ParserUtils::addSubFieldDescription(any_field, "behavior", JsonSchema::FieldType::STRING, true); 
     
    // Campo number_of_args
    ParserUtils::addSubFieldDescription(any_field, "number_of_args", JsonSchema::FieldType::UNSIGNED, true);

    // Campo activation
    ParserUtils::addSubFieldDescription(any_field, "activation", JsonSchema::FieldType::STRING, true);

    // Campos flags
    
    ParserUtils::addSubFieldDescription(any_field, "flags", JsonSchema::FieldType::OBJECT, true);


    // Sub Campos de flags
    JsonSchema::FieldDescription& flags = any_field.subFieldsFormats->at(4);
    ParserUtils::addSubFieldDescription(flags, JsonSchema::ANY , JsonSchema::FieldType::OBJECT, true);

    // Sub Campos dos Sub Campos de flags
    JsonSchema::FieldDescription& sub_flags = flags.subFieldsFormats->at(0);
    ParserUtils::addSubFieldDescription(sub_flags, "true", JsonSchema::FieldType::STRING, true);
    ParserUtils::addSubFieldDescription(sub_flags, "false", JsonSchema::FieldType::STRING, true);
}

void InstructionSetDescriptionParser::initializeDataFieldSchema() {
    json_schema["Data"].name = "Data";
    json_schema["Data"].type = JsonSchema::FieldType::OBJECT;
    json_schema["Data"].is_required = true;
    json_schema["Data"].subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Data"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Data"].subFieldsFormats->at(0); 

    // Campo syntax
    ParserUtils::addSubFieldDescription(any_field, "syntax", JsonSchema::FieldType::STRING, true);

    // Campo behavior
    ParserUtils::addSubFieldDescription(any_field, "behavior", JsonSchema::FieldType::STRING, true); 
     
    // Campo number_of_args
    ParserUtils::addSubFieldDescription(any_field, "number_of_args", JsonSchema::FieldType::UNSIGNED, true);
}
void InstructionSetDescriptionParser::initializeJsonSchema() {
    initializeArithmeticLogicFieldSchema();
    initializeJumperFieldSchema();
    initializeConditionalJumperFieldSchema();
    initializeDataFieldSchema();
}

void InstructionSetDescriptionParser::checkAndFindSubFields(const JsonSchema::FieldDescription& schema,const std::string& sub_field_name, const std::string& parent_field_name, const nlohmann::json& json) {
    const std::vector<std::reference_wrapper<JsonSchema::FieldDescription>> sub_fields_schemas = ParserUtils::getSubJsonSchema(schema, sub_field_name);
    bool is_found = (sub_fields_schemas.size() > 0) ? true : false;
    int num_of_matches = 0; // numero de desricoes compativeis   

    if (!is_found){
        success_parsing = false;
        std::cerr << "Sub Field '" << sub_field_name << "'" << " in " << "'" << parent_field_name << "'" << " not recognized" << std::endl;
    }
    
    for (const auto& sub_field_schema : sub_fields_schemas){
        if (ParserUtils::isEqualToDescription(json, sub_field_name,  sub_field_schema.get())){
            ++num_of_matches;
            sub_field_schema.get().is_found = true;
            if (json.is_object()){
                for (auto sub_field = json.begin(); sub_field != json.end(); ++sub_field){
                    checkAndFindSubFields(sub_field_schema.get(), sub_field.key(),sub_field_name, sub_field.value());
                }
            }
        }
    }
    
    if (num_of_matches == 1){
        return;
    }else if (num_of_matches > 1){
        success_parsing = false;
        std::cerr << "Sub Field " << "'"<< sub_field_name << "'" << " not unique" << std::endl;
    }else{
        success_parsing = false;
        for (const auto& sub_field_schema : sub_fields_schemas){
                std::cerr << "Sub Field " << "'" << sub_field_name << "'" << " in " << "'" << parent_field_name << "'" << " must have type " << ParserUtils::getFieldTypeName(sub_field_schema.get().type) << std::endl;
        }
    }

}
void InstructionSetDescriptionParser::checkAndFindField(const std::string& field_name) {
    if (json_schema.find(field_name) == nullptr){
        success_parsing = false;
        std::cerr << "Main Field '" << field_name << "' not recognized" << std::endl;
    }else{
        json_schema[field_name].is_found = true;
        if (machine_description_json[field_name].is_object()){
            for (auto sub_field = machine_description_json[field_name].begin(); sub_field != machine_description_json[field_name].end(); ++sub_field){
                checkAndFindSubFields(json_schema[field_name], sub_field.key(), field_name, sub_field.value());
            }
        }
        else{
            success_parsing = false;
            std::cerr << "Main Field '" << field_name << "' must have type OBJECT" << std::endl;
        }
    } 
}

void InstructionSetDescriptionParser::checkIfFieldIsFound(const JsonSchema::FieldDescription& field_description, const std::string& parent_field_name ) {

    if (!field_description.is_found && field_description.is_required){
        if (parent_field_name != "none"){
            std::cerr << "Required Sub Field '" << field_description.name << "' in '" << parent_field_name << "' not found" << std::endl;
            success_parsing = false;
        }else{
            std::cerr << "Required Main Field '" << field_description.name << "' " << "not found" << std::endl;
            success_parsing = false;
        }
    }else if (field_description.type == JsonSchema::FieldType::OBJECT){
        for (const auto& sub_field : *field_description.subFieldsFormats){
            checkIfFieldIsFound(sub_field, field_description.name);
        }
    }

}

void InstructionSetDescriptionParser::parseInstructionSetDescription() {
    for (auto field  = machine_description_json.begin(); field != machine_description_json.end(); ++field) {
        checkAndFindField(field.key());
    }

    for (const auto& field_schema : json_schema){
        checkIfFieldIsFound(field_schema.second);
    }

    if (success_parsing){
        std::cout << "Instruction set description parsed successfully!" << std::endl;
    }else{
        std::cerr << "Instruction set description parsing failed!" << std::endl;
    }
}
