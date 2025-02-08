#include <Machine.hpp>
#include <MachineDescription.h>
#include <iostream>
#include <BinaryUtils.hpp>
#include <bitset>

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
    Binary num_a = {0b10000101, 0b00010011};
    Binary num_b = {0b0101101,0b00000111};
    Binary result = BinaryUtils<Binary>::Add(num_a, num_b);
    uint8_t num_c = BinaryUtils<uint8_t>::Add(num_c, num_c);
    std::cout << std::bitset<8>(result[0]) << std::endl;
    std::cout << std::bitset<8>(result[1]) << std::endl;
    //initializeInteralRegisters();
    //initializeGeneralRegisters();
}