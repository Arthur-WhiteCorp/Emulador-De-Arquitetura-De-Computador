#ifndef INSTRUCTION_SET_DESCRIPTION_H
#define INSTRUCTION_SET_DESCRIPTION_H
#include <string>
#include <vector>
#include <cstdint>


namespace InstructionSetDescription {
    const std::string EMPTY_STRING = "";
    const std::uint8_t EMPTY_NUMBER = 0;
    

    struct InstructionDescription {
        std::string name;
        uint8_t number_of_arguments;
        std::string behavior;
        std::string syntax;
        InstructionDescription() = default;
        InstructionDescription(std::string name, std::string syntax, std::string behavior, uint8_t number_of_arguments) : name(name), number_of_arguments(number_of_arguments), behavior(behavior), syntax(syntax) {}
    };
    
    struct ALInstructionsDescription { // AL = Arithmetic Logic (instruções logicas aritméticas)
        InstructionDescription description;
        std::string flags_modification;
        ALInstructionsDescription()= default;
        ALInstructionsDescription(std::string name, std::string syntax, std::string behavior, uint8_t number_of_arguments, std::string flags_modification) : description(name, syntax, behavior, number_of_arguments), flags_modification(flags_modification) {}
    
    };
    
    
    struct JumperInstructionsDescription {
        InstructionDescription description;
        JumperInstructionsDescription()= default;
        JumperInstructionsDescription(std::string name, std::string syntax, std::string behavior, uint8_t number_of_arguments) : description(name, syntax, behavior, number_of_arguments) {}
    };
    
    
    struct FlagDescription {
        std::string name; // nome da flag: a, b, c e etc
        std::string true_;  // descreve quando a flag eh ativada
        std::string false_; // descreve quando a flag eh desativada
        FlagDescription() = default;
        FlagDescription(std::string name, std::string true_, std::string false_) : name(name), true_(true_), false_(false_) {}
    };
    
    
    struct ConditionalJumperInstructionsDescription {
        InstructionDescription description;
        std::string activation;
        std::vector<FlagDescription> flags;
        ConditionalJumperInstructionsDescription() = default;
        ConditionalJumperInstructionsDescription(std::string name, std::string syntax, std::string behavior, uint8_t number_of_arguments, std::string activation) : description(name, syntax, behavior, number_of_arguments), activation(activation) {}
    };
    
    struct DataInstructionsDescription {
        InstructionDescription description;
        DataInstructionsDescription() = default;
        DataInstructionsDescription(std::string name, std::string syntax, std::string behavior, uint8_t number_of_arguments) : description(name, syntax, behavior, number_of_arguments) {}
    };
    
    struct InputAndOutputInstructionsDescription {
        InstructionDescription description;
        InputAndOutputInstructionsDescription() = default;
        InputAndOutputInstructionsDescription(std::string name, std::string syntax, std::string behavior, uint8_t number_of_arguments) : description(name, syntax, behavior, number_of_arguments) {}
    };
    
    
    struct InstructionSetDescription {
        bool i_o_instrucitons_enabled; // flags de controle de habilitação de instruções de entrada e saida
        std::vector<ALInstructionsDescription> al_instructions;
        std::vector<JumperInstructionsDescription> jumper_instructions;
     
        std::vector<ConditionalJumperInstructionsDescription> conditional_jumper_instructions;
        std::vector<DataInstructionsDescription> data_instructions;
        std::vector<InputAndOutputInstructionsDescription> input_and_output_instructions;
        InstructionSetDescription() {} // construtor padrão
        InstructionSetDescription(const InstructionSetDescription& other);
        InstructionSetDescription& operator=(const InstructionSetDescription& other);
    };
    
}
    
#endif
