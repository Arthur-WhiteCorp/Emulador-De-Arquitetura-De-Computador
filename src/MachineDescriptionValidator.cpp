#include <MachineDescriptionValidator.hpp>
#include <MachineDescription.h>
#include <iostream>
#include <math.h>

MachineDescriptionValidator::MachineDescriptionValidator(const MachineDescription& machine_description)
    :machine_description(machine_description){
    initializeErrorFlags();
    checkMachineDescriptionValidity();
}

MachineDescriptionValidator::~MachineDescriptionValidator(){
}

void MachineDescriptionValidator::initializeErrorFlags(){
    is_valid = true;
}

bool MachineDescriptionValidator::isValid() {
    return is_valid;
}

void MachineDescriptionValidator::checkRegisterSize(std::string register_identifier, uint16_t register_size){
    if (register_identifier == machine_description.general_registers.id_pattern &&
        register_size > machine_description.general_registers.size_of_general_registers){
        is_valid = false;
        std::cerr << "General Registers '" << register_identifier << "_' sizes must be less than or equal to word_size!" << std::endl;
    }else if (register_size > machine_description.word_size){
        is_valid = false;
        std::cerr << "Register '" << register_identifier << "' size must be less than or equal to word_size!" << std::endl;
    }

}
void MachineDescriptionValidator::checkRegistersSizes(){
    checkRegisterSize(machine_description.program_counter.identifier, machine_description.program_counter.size);
    checkRegisterSize(machine_description.flags_register.identifier, machine_description.flags_register.size);
    checkRegisterSize(machine_description.general_registers.id_pattern, machine_description.general_registers.size_of_general_registers);
}

void MachineDescriptionValidator::checkRegistersIdentifiers(){
    const auto& program_counter_id = machine_description.program_counter.identifier;
    const auto& flags_register_id = machine_description.flags_register.identifier;
    const auto& general_registers_id_pattern = machine_description.general_registers.id_pattern;

    if (program_counter_id == flags_register_id){
        is_valid = false;
        std::cerr << "Program counter, flags register, and general registers must have unique identifiers." 
                    << std::endl;
    }

    
    for (const auto& general_register : machine_description.general_registers.registers){
        if (program_counter_id == general_register.identifier ||
            flags_register_id == general_register.identifier){
            is_valid = false;
            std::cerr << "Program counter, flags register, and general registers must have unique identifiers." 
                        << std::endl;
        }
    }

}

void MachineDescriptionValidator::checkMemorySize(){
    std::uint64_t max_memory_size = pow(2, machine_description.word_size);
    if (machine_description.memory_size > max_memory_size){
        is_valid = false;
        std::cerr << "'memory_size' must be less than or equal to 2^word_size!" << std::endl;    
    }
}

void MachineDescriptionValidator::checkInstructionSize(){
    if (machine_description.instruction_size > machine_description.word_size){
        is_valid = false;
        std::cerr << "'instruction_size' must be less than or equal to word_size!" << std::endl;
    }
}

void MachineDescriptionValidator::checkRegisterAddressSize(){
    if (machine_description.register_address_size > machine_description.word_size){
        is_valid = false;
        std::cerr << "'register_address_size' must be less than or equal to word_size!" << std::endl;
    }
}

void MachineDescriptionValidator::validateInstructionAndRegisterAddressSize(){
    std::uint16_t total_size = machine_description.register_address_size + machine_description.instruction_size;

    if (total_size > machine_description.word_size){
        is_valid = false;
        std::cerr << "not enough space for instruction and register address!" << std::endl;
        std::cerr << "'register_address_size' + 'instruction_size' > word_size" << std::endl;

    }
}
void MachineDescriptionValidator::checkMachineDescriptionValidity(){
    checkRegistersSizes();
    checkRegistersIdentifiers();
    checkMemorySize();
    checkInstructionSize();
    checkRegisterAddressSize();
    validateInstructionAndRegisterAddressSize();
}