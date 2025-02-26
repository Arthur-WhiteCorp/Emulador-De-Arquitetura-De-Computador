#include <InstructionSetDescriptionParser.hpp>
#include <JsonSchema.h>
#include <memory>
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
}

void InstructionSetDescriptionParser::initializeArithmeticLogicFieldSchema() {
    json_schema["Arithmetic_Logic"].name = "Arithmetic_Logic";
    json_schema["Arithmetic_Logic"].type = FieldType::Object;
    json_schema["Arithmetic_Logic"].isRequired = false;
    json_schema["Arithmetic_Logic"].subFieldsFormats = std::make_unique<std::vector<FieldDescription>>();
    json_schema["Arithmetic_Logic"].subFieldsFormats->push_back(FieldDescription());
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).name = "Any"; // Pode ser qualquer string
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).type = FieldType::String;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).isRequired = false;
    json_schema["Arithmetic_Logic"].subFieldsFormats->at(0).constraints = FieldConstraints();

}

void InstructionSetDescriptionParser::initializeJsonSchema() {
    initializeArithmeticLogicFieldSchema();    
}

void InstructionSetDescriptionParser::checkSubFieldsValidity(const std::string& parent_field_name) {
}

void InstructionSetDescriptionParser::checkFieldValidity(const std::string& field_name) {
    if (json_schema.find(field_name) == nullptr){
        success_parsing = false;
        std::cerr << "Field " << field_name << " not recognized" << std::endl;
    }else{
        checkSubFieldsValidity(field_name);
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
