#include <InstructionSetDescription.h>
#include <JsonFieldDescription.h>
#include <InstructionSetDescriptionParser.hpp>
#include <JsonSchema.h>
#include <memory>
#include <ParserUtils.hpp>
#include <iostream>

InstructionSetDescriptionParser::InstructionSetDescriptionParser(std::string file_path): handler(file_path) {
    initializeErrorFlags();
    if (handler.isValidJson()){
        instruction_set_description_json = handler.getJson();
        putMainFieldsInSchema();
        fillFieldFillers(); // kkkkkk
        parseInstructionSetDescription();
    }else{
        success_parsing = false;
    }
}
InstructionSetDescriptionParser::~InstructionSetDescriptionParser() {
    
}
 
void InstructionSetDescriptionParser::initializeErrorFlags() {
    success_parsing = true;    
}

bool InstructionSetDescriptionParser::isSuccessful() {
    return success_parsing;
}

void InstructionSetDescriptionParser::fillFieldFillers() {
     field_fillers["Arithmetic_Logic"] = [&](const nlohmann::json& json, const std::string& instruction_name) {
        if (json.find("behavior") != json.end()){
            instruction_set_description.al_instructions.emplace_back(instruction_name, json["syntax"].get<std::string>(), json["behavior"].get<std::string>(), json["number_of_args"].get<unsigned>(), json["flags_modification"].get<std::string>());
        }else{ 
            instruction_set_description.al_instructions.emplace_back(instruction_name, json["syntax"].get<std::string>(),InstructionSetDescription::EMPTY_STRING, json["number_of_args"].get<unsigned>(), json["flags_modification"].get<std::string>());

        }
    };

    field_fillers["Jumper"] = [&](const nlohmann::json& json, const std::string& instruction_name) {
        instruction_set_description.jumper_instructions.emplace_back(instruction_name, json["syntax"].get<std::string>(), json["behavior"].get<std::string>(), json["number_of_args"].get<unsigned>());
    }; 

    field_fillers["Conditional_Jumper"] = [&](const nlohmann::json& json, const std::string& instruction_name) {
        instruction_set_description.conditional_jumper_instructions.emplace_back(instruction_name, json["syntax"].get<std::string>(), json["behavior"].get<std::string>(), json["number_of_args"].get<unsigned>(), json["activation"].get<std::string>());
        
        for (auto flag = json["flags"].begin(); flag != json["flags"].end(); ++flag){
            instruction_set_description.conditional_jumper_instructions.back().flags.emplace_back(flag.key(), flag.value()["true"].get<std::string>(), flag.value()["false"].get<std::string>());
        }

    };

    field_fillers["Data"] = [&](const nlohmann::json& json, const std::string& instruction_name) {
        instruction_set_description.data_instructions.emplace_back(instruction_name, json["syntax"].get<std::string>(), json["behavior"].get<std::string>(), json["number_of_args"].get<unsigned>());
    };
 
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
    json_schema["Arithmetic_Logic"].sub_fields_formats = std::make_shared<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Arithmetic_Logic"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Arithmetic_Logic"].sub_fields_formats->at(0); 

    // Campo syntax
    ParserUtils::addSubFieldDescription(any_field, "syntax", JsonSchema::FieldType::STRING, true);

    // Campo behavior
    ParserUtils::addSubFieldDescription(any_field, "behavior", JsonSchema::FieldType::STRING, false); 
     
    // Campo number_of_args
    ParserUtils::addSubFieldDescription(any_field, "number_of_args", JsonSchema::FieldType::UNSIGNED, true);

    // Campo flags_modification
    ParserUtils::addSubFieldDescription(any_field, "flags_modification", JsonSchema::FieldType::STRING, true);
}
void InstructionSetDescriptionParser::initializeJumperFieldSchema() {
    json_schema["Jumper"].name = "Jumper";
    json_schema["Jumper"].type = JsonSchema::FieldType::OBJECT;
    json_schema["Jumper"].is_required = true;
    json_schema["Jumper"].sub_fields_formats = std::make_shared<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Jumper"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Jumper"].sub_fields_formats->at(0); 

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
    json_schema["Conditional_Jumper"].sub_fields_formats = std::make_shared<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Conditional_Jumper"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Conditional_Jumper"].sub_fields_formats->at(0); 

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
    JsonSchema::FieldDescription& flags = any_field.sub_fields_formats->at(4);
    ParserUtils::addSubFieldDescription(flags, JsonSchema::ANY , JsonSchema::FieldType::OBJECT, true);

    // Sub Campos dos Sub Campos de flags
    JsonSchema::FieldDescription& sub_flags = flags.sub_fields_formats->at(0);
    ParserUtils::addSubFieldDescription(sub_flags, "true", JsonSchema::FieldType::STRING, true);
    ParserUtils::addSubFieldDescription(sub_flags, "false", JsonSchema::FieldType::STRING, true);
}

void InstructionSetDescriptionParser::initializeDataFieldSchema() {
    json_schema["Data"].name = "Data";
    json_schema["Data"].type = JsonSchema::FieldType::OBJECT;
    json_schema["Data"].is_required = true;
    json_schema["Data"].sub_fields_formats = std::make_shared<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções Any indica que podem ter qualquer nome
    ParserUtils::addSubFieldDescription(json_schema["Data"], JsonSchema::ANY, JsonSchema::FieldType::OBJECT, true);
    JsonSchema::FieldDescription& any_field = json_schema["Data"].sub_fields_formats->at(0); 

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

void InstructionSetDescriptionParser::checkSubFields(const JsonSchema::FieldDescription& schema,const std::string& sub_field_name, const std::string& parent_field_name, const nlohmann::json& json) {
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
            if (num_of_matches == 1){
                sub_field_schema.get().field_data.emplace_back(JsonSchema::FieldData(sub_field_name, std::make_shared<const nlohmann::json>(json)));
            }
            if (json.is_object()){
                for (auto sub_field = json.begin(); sub_field != json.end(); ++sub_field){
                    checkSubFields(sub_field_schema.get(), sub_field.key(),sub_field_name, sub_field.value());
                }
            }
        }
    }
    if (num_of_matches == 1){
        return;
    }else if (num_of_matches > 1){
        success_parsing = false;
        std::cerr << "Sub Field " << "'"<< sub_field_name << "'" << " in " << "'" << parent_field_name << "'" << " matches more than one description" << std::endl;
    }else{
        success_parsing = false;
        for (const auto& sub_field_schema : sub_fields_schemas){
                std::cerr << "Sub Field " << "'" << sub_field_name << "'" << " in " << "'" << parent_field_name << "'" << " must have type " << ParserUtils::getFieldTypeName(sub_field_schema.get().type) << std::endl;
        }
    }

}
void InstructionSetDescriptionParser::checkField(const std::string& field_name) {
    if (json_schema.find(field_name) == nullptr){
        success_parsing = false;
        std::cerr << "Main Field '" << field_name << "' not recognized" << std::endl;
    }else{
        if (instruction_set_description_json[field_name].is_object()){
            json_schema[field_name].field_data.emplace_back(JsonSchema::FieldData(field_name, std::make_shared<const nlohmann::json>(instruction_set_description_json[field_name])));
            for (auto sub_field = instruction_set_description_json[field_name].begin(); sub_field != instruction_set_description_json[field_name].end(); ++sub_field){
                checkSubFields(json_schema[field_name], sub_field.key(), field_name, sub_field.value());
            }
        }
        else{
            success_parsing = false;
            std::cerr << "Main Field '" << field_name << "' must have type OBJECT" << std::endl;
        }
    } 
}

void InstructionSetDescriptionParser::checkForMissingSubFields(const JsonSchema::FieldDescription& field_description) {
    bool is_required;
    bool is_any;
    for (const auto& field : field_description.field_data){
        if (field_description.sub_fields_formats == nullptr){
            continue;
        }
        for (const auto& sub_field_description : *field_description.sub_fields_formats){
            is_any = (sub_field_description.name == JsonSchema::ANY) ? true : false;
            is_required = (sub_field_description.is_required) ? true : false;
            if ((field.field_value->find(sub_field_description.name) == field.field_value->end()  && sub_field_description.is_required) && !is_any) {
                success_parsing = false;
                std::cerr << "Sub Field '" << sub_field_description.name << "'" << " in " << "'" << field.field_name << "'" << " not found" << std::endl;                
            }else if (field.field_value->is_object()){
                checkForMissingSubFields(sub_field_description);
            }
        } 
    }
}




void InstructionSetDescriptionParser::checkForMissingFields() {
    for (const auto& field_description : json_schema){
        if (instruction_set_description_json.find(field_description.first) == instruction_set_description_json.end() && field_description.second.is_required){
            success_parsing = false;
            std::cerr << "Main Field '" << field_description.first << "' not found" << std::endl;
        }else{
            checkForMissingSubFields(field_description.second);
        }
    }
}

InstructionSetDescription::InstructionSetDescription InstructionSetDescriptionParser::getInstructionSetDescription() {
    return instruction_set_description;
}
void InstructionSetDescriptionParser::fillInstructionSetDescription() {
    for (const auto& field : json_schema){
        for (const auto& field_data : field.second.sub_fields_formats->at(0).field_data){
            if (field_fillers.find(field.first) != field_fillers.end()){
                field_fillers[field.first](*field_data.field_value, field_data.field_name);
            }
        }
    }
}

void InstructionSetDescriptionParser::parseInstructionSetDescription() {
    for (auto field  = instruction_set_description_json.begin(); field != instruction_set_description_json.end(); ++field) {
        checkField(field.key());
    }
    
    checkForMissingFields();


    if (success_parsing){
        std::cout << "Instruction set description parsed successfully!" << std::endl;
        fillInstructionSetDescription();
    }else{
        std::cerr << "Instruction set description parsing failed!" << std::endl;
    }
}
