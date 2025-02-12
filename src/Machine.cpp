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
    Byte zero(0b00000000); // 8 bits
    memory.data.assign(memory.size, zero); // inicializa com zeros
}

void Machine::initializeGeneralRegisters(){
    uint16_t general_registers_size = machine_description.general_registers.size_of_general_registers;
    size_t size = general_registers_size/8;
    Binary zero(general_registers_size/8, 0); // cria um zero de 8, 16, 32, 64 ou 128 bits dependendo do tamanho do general_registers
    // tenho que decidir como vai ficar esse tamanho (talvez mude algo no validator)
    Byte zero_byte(0b00000000);
    //for (const auto& register_ : machine_description.general_registers.registers){
    //    id_to_binary
    //}
}


void Machine::initializeMachine(){
    initializeMemory();
    initializeGeneralRegisters();




    Binary num_a = {0b10000101, 0b00010011};
    Binary num_b = {0b0101101,0b00000111};
    Binary result_sum = BinaryUtils<Binary>::Add(num_a, num_b);
    Binary result_sub = BinaryUtils<Binary>::Subtract(num_a, num_b);
    Binary result_mult = BinaryUtils<Binary>::Multiply(num_a, num_b);
    Binary result_div = BinaryUtils<Binary>::Divide(num_a, num_b);
    Binary result_rem = BinaryUtils<Binary>::Remainder(num_a, num_b);
    Binary result_and = BinaryUtils<Binary>::And(num_a, num_b);
    Binary result_or = BinaryUtils<Binary>::Or(num_a, num_b);
    Binary result_xor = BinaryUtils<Binary>::Xor(num_a, num_b);
    Binary result_not = BinaryUtils<Binary>::Not(num_a);
    Binary result_shift_left = BinaryUtils<Binary>::ShiftLeft(num_a,4);
    Binary result_shift_right = BinaryUtils<Binary>::ShiftRight(num_a,4);
    std::cout << "======================="<< std::endl;

    std::cout << "num_a: " << num_a << std::endl;
    std::cout << "num_b: " << num_b << std::endl;
    std::cout << "sum:   " << result_sum << std::endl;
    std::cout << "sub:   " << result_sub << std::endl;
    std::cout << "mult:  " << result_mult << std::endl;
    std::cout << "div:   " << result_div << std::endl;
    std::cout << "rem:   " << result_rem << std::endl;


    std::cout << "======================="<< std::endl;
    std::cout << "num_a: " << num_a << std::endl;
    std::cout << "num_b: " << num_b << std::endl;
    std::cout << "and:   " << result_and << std::endl;
    std::cout << "or:    " << result_or << std::endl;
    std::cout << "xor:   " << result_xor << std::endl;
    std::cout << "not:   " << result_not << std::endl;
    std::cout << "shl:   " << result_shift_left << std::endl;
    std::cout << "shr:   " << result_shift_right << std::endl;

    // erro para teste

   
}