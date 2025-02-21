#include <InstructionSetDescriptionParser.hpp>


InstructionSetDescriptionParser::InstructionSetDescriptionParser(std::string file_path): handler(file_path) {
    initializeErrorFlags();
    if (handler.isValidJson()){
        machine_description_json = handler.getJson();
        parseInstructionSetDescription();
    }
}
InstructionSetDescriptionParser::~InstructionSetDescriptionParser() {
    
}

void InstructionSetDescriptionParser::initializeErrorFlags() {
    success_parsing = true;    
}
void InstructionSetDescriptionParser::parseInstructionSetDescription() {
    
}
