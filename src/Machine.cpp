#include <Machine.hpp>
#include <MachineDescription.h>
#include <iostream>

Machine::Machine(MachineDescription machine_description)
    :machine_description(machine_description){
    initializeErrorFlags();
    if (isMachineDescriptionValid(machine_description)){
        initializeMachine();
    };
}

Machine::~Machine(){
}

void Machine::initializeErrorFlags(){
    
}

bool Machine::isMachineDescriptionValid(const MachineDescription& machine_description){
    machine_description_validator = std::make_unique<MachineDescriptionValidator>(machine_description);
    return machine_description_validator->isValid();
}

void Machine::initializeMemory(){
    memory.size = machine_description.memory_size;
    Byte  zero = (Byte) 8; // 8 bits
    memory.data.assign(memory.size, zero); // inicializa com zeros
}
void Machine::initializeMachine(){
    initializeMemory();
    //initializeInteralRegisters();
    //initializeGeneralRegisters();
}