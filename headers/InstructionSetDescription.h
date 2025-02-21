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


struct FlagDescription {
    std::string name; // nome da flag: a, b, c e etc
    std::string true_;  // descreve quando a flag eh ativada
    std::string false_; // descreve quando a flag eh desativada
};


struct ConditioanlJumperInstructionsDescription {
    InstructionDescription description;
    std::string activation;
    std::vector<FlagDescription> flags;
};

struct DataInstructionsDescription {
    InstructionDescription description;
};

struct InputAndOutputInstructionsDescription {
    InstructionDescription description;
};


struct InstructionSetDescription {
    bool i_o_instrucitons_enabled; // flags de controle de habilitação de instruções de entrada e saida
    std::vector<ALInstructionsDescription> al_instructions;
    std::vector<JumperInstructionsDescription> jumper_instructions;
    std::vector<ConditioanlJumperInstructionsDescription> conditional_jumper_instructions;
    std::vector<DataInstructionsDescription> data_instructions;
    std::vector<InputAndOutputInstructionsDescription> input_and_output_instructions;
    InstructionSetDescription() {} // construtor padrão
    InstructionSetDescription(const InstructionSetDescription& other);
    InstructionSetDescription& operator=(const InstructionSetDescription& other);
};



#endif
