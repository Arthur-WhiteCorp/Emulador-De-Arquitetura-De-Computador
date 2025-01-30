// machine_description.cpp

#include <MachineDescription.h>

MachineDescription::MachineDescription(const MachineDescription& other) {
    // Copy constructor implementation
    instruction_size = other.instruction_size;
    memory_size = other.memory_size;
    program_counter = other.program_counter;
    flags_register = other.flags_register;
    general_registers = other.general_registers;
}

MachineDescription& MachineDescription::operator=(const MachineDescription& other) {
    // Assignment operator implementation
    if (this != &other) {
        instruction_size = other.instruction_size;
        memory_size = other.memory_size;
        program_counter = other.program_counter;
        flags_register = other.flags_register;
        general_registers = other.general_registers;
    }
    return *this;
}