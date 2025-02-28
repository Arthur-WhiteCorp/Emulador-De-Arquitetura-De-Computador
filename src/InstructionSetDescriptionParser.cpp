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
    json_schema["Arithmetic_Logic"] = FieldDescription();
    json_schema["Jumper"] = FieldDescription();
    json_schema["Conditional_Jumper"] = FieldDescription();
    json_schema["Data"] = FieldDescription();

    initializeJsonSchema();
}

void InstructionSetDescriptionParser::initializeArithmeticLogicFieldSchema() {
    json_schema["Arithmetic_Logic"].name = "Arithmetic_Logic";
    json_schema["Arithmetic_Logic"].type = FieldType::OBJECT;
    json_schema["Arithmetic_Logic"].isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats = std::make_unique<std::vector<FieldDescription>>();


    // Campos de Insstruções any indica que podem ter qualquer nome
    json_schema["Arithmetic_Logic"].subFieldsFormats->push_back(FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).name = "Any"; // Pode ser qualquer string
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).type = FieldType::OBJECT;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).constraints = FieldConstraints();
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats = std::make_unique<std::vector<FieldDescription>>();

    // Campo syntax
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).name = "syntax"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).type = FieldType::STRING;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).constraints = FieldConstraints();
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).subFieldsFormats = std::make_unique<std::vector<FieldDescription>>();

    // Campo behavior
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).name = "behavior"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).type = FieldType::STRING;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).constraints = FieldConstraints();
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).subFieldsFormats = std::make_unique<std::vector<FieldDescription>>();
    
    // Campo number_of_args
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).name = "number_of_args"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).type = FieldType::UNSIGNED;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).constraints = FieldConstraints();
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).subFieldsFormats = std::make_unique<std::vector<FieldDescription>>();

    // Campo flags_modification
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).name = "flags_modification"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).type = FieldType::STRING;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).constraints = FieldConstraints();
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).subFieldsFormats = std::make_unique<std::vector<FieldDescription>>();
}
 
void InstructionSetDescriptionParser::initializeJsonSchema() {
    initializeArithmeticLogicFieldSchema();    
}

void InstructionSetDescriptionParser::checkSubFieldsValidity(const std::string& sub_field_name, const nlohmann::json& json) {
    if ( ParserUtils::isEqualToDescription(json, sub_field_name, json_schema[sub_field_name]) ){
        success_parsing = true;
        std::cout << "Field " << sub_field_name << " is valid" << std::endl;
    }else{
        success_parsing = false;
        std::cerr << "Field " << sub_field_name << " is not valid" << std::endl;
    }
}
void InstructionSetDescriptionParser::checkFieldValidity(const std::string& field_name) {
    if (json_schema.find(field_name) == nullptr){
        success_parsing = false;
        std::cerr << "Main Field " << field_name << " not recognized" << std::endl;
    }else{
        if (machine_description_json[field_name].is_object()){
            for (auto sub_field = machine_description_json[field_name].begin(); sub_field != machine_description_json[field_name].end(); ++sub_field){
                checkSubFieldsValidity(sub_field.key(), sub_field.value());
            }
        }
        else{
            success_parsing = false;
        }
    } 
}


void InstructionSetDescriptionParser::parseInstructionSetDescription() {
    for (auto field  = machine_description_json.begin(); field != machine_description_json.end(); ++field) {
        checkFieldValidity(field.key());
    } 
    if (success_parsing){
        std::cout << "Instruction set description parsed successfully!" << std::endl;
    }else{
        std::cerr << "Instruction set description parsing failed!" << std::endl;
    }
}
