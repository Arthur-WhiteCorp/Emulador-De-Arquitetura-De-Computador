#include <MachineDescriptionValidator.hpp>
#include <MachineDescription.h>
#include <iostream>

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

bool MachineDescriptionValidator::checkPrefixesEquality(const std::string& register_identifier_a, const std::string& register_identifier_b, std::size_t prefix_size){
    const std::string prefix_a = register_identifier_a.substr(0, prefix_size);
    const std::string prefix_b = register_identifier_b.substr(0, prefix_size);
    if (register_identifier_a.size() < prefix_size || 
        register_identifier_b.size() < prefix_size) {
        return false; // string muito curta
    }
    return prefix_a == prefix_b;
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
void MachineDescriptionValidator::checkMachineDescriptionValidity(){
    checkRegistersSizes();
    checkRegistersIdentifiers();
    //checkMemorySize();
    //checkInstructionSet();  

}