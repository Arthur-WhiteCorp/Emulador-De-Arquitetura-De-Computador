#include <Machine.hpp>
#include <MachineDescription.h>
#include <iostream>

Machine::Machine(MachineDescription machine_description){
    initializeErrorFlags();
    loadMachineDescription(machine_description);
    checkMachineDescriptionValidity();
}

Machine::~Machine(){
}

void Machine::initializeErrorFlags(){
    is_description_valid = true;
}
void Machine::loadMachineDescription(MachineDescription machine_description_struct){
    machine_description = machine_description_struct; 
}

void Machine::checkRegisterSize(std::string register_identifier, uint16_t register_size){
    if (register_identifier == machine_description.general_registers.id_pattern){
        std::cerr << "General Registers '" << register_identifier << "_' sizes must be less than word_size!" << std::endl;
    }else if (register_size > machine_description.word_size){
        is_description_valid = false;
        std::cerr << "Register '" << register_identifier << "' size must be less than word_size!" << std::endl;
    }

}
void Machine::checkRegistersSizes(){
    checkRegisterSize(machine_description.program_counter.identifier, machine_description.program_counter.size);
    checkRegisterSize(machine_description.flags_register.identifier, machine_description.flags_register.size);
    checkRegisterSize(machine_description.general_registers.id_pattern, machine_description.general_registers.size_of_general_registers);
}
void Machine::checkMachineDescriptionValidity(){
    checkRegistersSizes();
    //checkMemorySize();
    //checkInstructionSet();  

}