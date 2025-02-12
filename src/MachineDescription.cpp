#include <MachineDescription.h>
#include <iostream>
MachineDescription::MachineDescription(const MachineDescription& other) {
    word_size = other.word_size;
    register_address_size = other.register_address_size;
    alu_instruction_size = other.alu_instruction_size;
    memory_size = other.memory_size;
    program_counter = other.program_counter;
    flags_register = other.flags_register;
    general_registers.id_pattern = other.general_registers.id_pattern;
    general_registers.number_of_general_registers = other.general_registers.number_of_general_registers;
    general_registers.size_of_general_registers = other.general_registers.size_of_general_registers;
    general_registers.registers.resize(other.general_registers.number_of_general_registers);
    for (unsigned int i = 0; i < other.general_registers.number_of_general_registers; i++){
        general_registers.registers[i] = other.general_registers.registers[i];
    }

}

MachineDescription& MachineDescription::operator=(const MachineDescription& other) {
    if (this != &other) {
        word_size = other.word_size;
        register_address_size = other.register_address_size;
        alu_instruction_size = other.alu_instruction_size;
        memory_size = other.memory_size;
        program_counter = other.program_counter;
        flags_register = other.flags_register;
        general_registers.id_pattern = other.general_registers.id_pattern;
        general_registers.number_of_general_registers = other.general_registers.number_of_general_registers;
        general_registers.size_of_general_registers = other.general_registers.size_of_general_registers;
        general_registers.registers.resize(other.general_registers.number_of_general_registers);
        for (unsigned int i = 0; i < other.general_registers.number_of_general_registers; i++){
            general_registers.registers[i] = other.general_registers.registers[i];
        }
    }
    return *this;
}