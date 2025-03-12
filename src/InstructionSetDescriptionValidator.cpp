#include <InstructionSetDescriptionValidator.hpp>
#include <InstructionPattern.h>
#include <regex.h>
#include <iostream>

InstructionSetDescriptionValidator::InstructionSetDescriptionValidator(const InstructionSetDescription::InstructionSetDescription& instruction_set_description, const MachineDescription& machine_description): instruction_set_description(instruction_set_description), machine_description(machine_description){
    fillInstructionsPatterns();    
    validate();
}

InstructionSetDescriptionValidator::~InstructionSetDescriptionValidator(){


}

bool InstructionSetDescriptionValidator::isValid(){
    return is_valid; 
}

void InstructionSetDescriptionValidator::fillInstructionsPatterns(){
    instructions_patterns["AL"] = InstructionPattern::InstructionPattern(
        R"((\w+)(\s(\w+))*)", 
        R"((\w+)\s=\s((-)?\w+)(\s(\+|\-)\s(\w+))*)"
    );
    
    instructions_patterns["AL"].flags_modification = std::make_unique<std::regex>(R"((\()(\w+)(\))(\?))");
    instructions_patterns["AL"].reserved_words["MAX"] = "MAX";
    instructions_patterns["AL"].reserved_words["MIN"] = "MIN";

    instructions_patterns["Data"];
    instructions_patterns["Condional_Jumper"];
    instructions_patterns["Jumper"];
    instructions_patterns["Input_Output"];
}


void InstructionSetDescriptionValidator::matchField(const std::string& input, const std::regex& regex){
    std::regex_iterator<std::string::const_iterator> it(input.begin(), input.end(), regex);
    std::regex_iterator<std::string::const_iterator> end_it;

    std::string::const_iterator last_end = input.begin();

    std::cout << "avaliando: " << std::endl;
    std::cout << input << std::endl;
    for (; it != end_it; ++it) {
        std::smatch match = *it;

        if (match.prefix().length() > 0) {
            std::cerr << "Unexpected text: " << match.prefix() << std::endl;
            is_valid = false;
        }

        last_end = match.suffix().first;
    }

    if (last_end != input.end()) {
        std::cout << "Unexpected text: " << std::string(last_end, input.end()) << std::endl;
        is_valid = false;
    }


}

void InstructionSetDescriptionValidator::validateALInstructions(){
    const std::regex& syntax = instructions_patterns["AL"].syntax;
    const std::regex& behavior = instructions_patterns["AL"].behavior;
    const std::regex& flags_modification = *instructions_patterns["AL"].flags_modification;
    std::smatch match;
    bool is_matched;
    for (const auto& instruction : instruction_set_description.al_instructions){
        if (instruction.description.behavior != ""){
            matchField(instruction.description.behavior, behavior);
        } 
        matchField(instruction.flags_modification,flags_modification);

        return;
        
    } 
}

void InstructionSetDescriptionValidator::validateJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validateDataInstructions(){
    
}

void InstructionSetDescriptionValidator::validateConditionalJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validate(){
    std::cout << "começando validação" << std::endl;
    validateALInstructions(); 
}


