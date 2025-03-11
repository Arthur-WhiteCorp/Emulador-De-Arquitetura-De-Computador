#include <InstructionSetDescriptionValidator.hpp>
#include <InstructionPattern.h>
#include <regex.h>

InstructionSetDescriptionValidator::InstructionSetDescriptionValidator(const InstructionSetDescription::InstructionSetDescription& instruction_set_description, const MachineDescription& machine_description): instruction_set_description(instruction_set_description), machine_description(machine_description){
    fillInstructionsPatterns();    
}

InstructionSetDescriptionValidator::~InstructionSetDescriptionValidator(){


}

void InstructionSetDescriptionValidator::fillInstructionsPatterns(){
    instructions_patterns["AL"] = InstructionPattern::InstructionPattern(
        R"((\w+)(\s(\w+))*)", 
        "todo"
    );
    instructions_patterns["Data"];
    instructions_patterns["Condional_Jumper"];
    instructions_patterns["Jumper"];
    instructions_patterns["Input_Output"];
}


void InstructionSetDescriptionValidator::validateALInstructions(){
        
}

void InstructionSetDescriptionValidator::validateJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validateDataInstructions(){
    
}

void InstructionSetDescriptionValidator::validateConditionalJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validate(){
    
}

bool InstructionSetDescriptionValidator::isValid(){
    return is_valid; 
}
