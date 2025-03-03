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
    json_schema["Arithmetic_Logic"].isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();


    // Campos de Insstruções any indica que podem ter qualquer nome
    json_schema["Arithmetic_Logic"].subFieldsFormats->push_back(JsonSchema::FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).name = "Any"; // Pode ser qualquer string
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).type = JsonSchema::FieldType::OBJECT;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();

    // Campo syntax
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(JsonSchema::FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).name = "syntax"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).type = JsonSchema::FieldType::STRING;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(0).subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();

    // Campo behavior
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(JsonSchema::FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).name = "behavior"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).type = JsonSchema::FieldType::STRING;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(1).subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();
    
    // Campo number_of_args
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(JsonSchema::FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).name = "number_of_args"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).type = JsonSchema::FieldType::UNSIGNED;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(2).subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();

    // Campo flags_modification
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->push_back(JsonSchema::FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).name = "flags_modification"; 
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).type = JsonSchema::FieldType::STRING;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).isRequired = true;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).subFieldsFormats->at(3).subFieldsFormats = std::make_unique<std::vector<JsonSchema::FieldDescription>>();
}
 
void InstructionSetDescriptionParser::initializeJsonSchema() {
    initializeArithmeticLogicFieldSchema();    
}

void InstructionSetDescriptionParser::checkSubFieldsValidity(const JsonSchema::FieldDescription& schema,const std::string& sub_field_name, const nlohmann::json& json) {
    const std::vector<std::reference_wrapper<JsonSchema::FieldDescription>> sub_field_description = ParserUtils::getSubJsonSchema(schema, sub_field_name);
    bool is_found = (sub_field_description.size() > 0) ? true : false;
    int num_of_matches = 0; // numero de desricoes compativeis   

    if (!is_found){
        success_parsing = false;
        std::cerr << "Sub Field: " << sub_field_name << " not recognized" << std::endl;
    }
    
    for (const auto& sub_field : sub_field_description){
        if (ParserUtils::isEqualToDescription(json, sub_field_name,  sub_field.get())){
            ++num_of_matches;
        }
    }
    
    if (num_of_matches == 1){
        return;
    }else if (num_of_matches > 1){
        success_parsing = false;
        std::cerr << "Sub Field " << sub_field_name << " not unique" << std::endl;
    }else{
        success_parsing = false;
        for (const auto& sub_field : sub_field_description){
                std::cerr << "Sub Field " << sub_field_name << " must have type " << ParserUtils::getFieldTypeName(sub_field.get().type) << std::endl;
        }
    }

}
void InstructionSetDescriptionParser::checkFieldValidity(const std::string& field_name) {
    if (json_schema.find(field_name) == nullptr){
        success_parsing = false;
        std::cerr << "Main Field " << field_name << " not recognized" << std::endl;
    }else{
        if (machine_description_json[field_name].is_object()){
            for (auto sub_field = machine_description_json[field_name].begin(); sub_field != machine_description_json[field_name].end(); ++sub_field){
                checkSubFieldsValidity(json_schema[field_name], sub_field.key(), sub_field.value());
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
