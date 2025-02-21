#include <InstructionSetDescription.h>


InstructionSetDescription::InstructionSetDescription(const InstructionSetDescription& other) {
    this->i_o_instrucitons_enabled = other.i_o_instrucitons_enabled;
    this->al_instructions = other.al_instructions;
    this->jumper_instructions = other.jumper_instructions;
    this->conditional_jumper_instructions = other.conditional_jumper_instructions;
    this->data_instructions = other.data_instructions;
    this->input_and_output_instructions = other.input_and_output_instructions;
}

InstructionSetDescription& InstructionSetDescription::operator=(const InstructionSetDescription& other) {
    if (this != &other){
        this->i_o_instrucitons_enabled = other.i_o_instrucitons_enabled;
        this->al_instructions = other.al_instructions;
        this->jumper_instructions = other.jumper_instructions;
        this->conditional_jumper_instructions = other.conditional_jumper_instructions;
        this->data_instructions = other.data_instructions;
        this->input_and_output_instructions = other.input_and_output_instructions;
    }
    return *this;
}
