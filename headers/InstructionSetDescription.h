#ifndef INSTRUCTION_SET_DESCRIPTION_H
#define INSTRUCTION_SET_DESCRIPTION_H
#include <string>
#include <vector>
#include <cstdint>

struct InstructionDescription {
    std::string name;
    uint8_t number_of_arguments;
    std::string behavior; 
};

struct ALInstructionsDescription { // AL = Arithmetic Logic (instruções logicas aritméticas)
    InstructionDescription description;
    std::string flags_modification;
};


struct JumperInstructionsDescription {
    InstructionDescription description;
};

struct ConditioanlJumperInstructionsDescription {
    InstructionDescription description;
    
};


struct InstructionSetDescription {
};
#endif
