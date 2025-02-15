#include <Machine.hpp>
#include <MachineDescription.h>
#include <iostream>
#include <BinaryUtils.hpp>
#include <bitset>

Machine::Machine(MachineDescription machine_description):
    machine_description(machine_description),machine_description_validator(machine_description){
    initializeErrorFlags();
    if (isMachineDescriptionValid(machine_description)){
        initializeMachine();
    };
    
    loadInstructionSet();
}

Machine::~Machine(){
}

void Machine::initializeErrorFlags(){
    
}

bool Machine::isMachineDescriptionValid(const MachineDescription& machine_description){
    return machine_description_validator.isValid();
}

void Machine::initializeMemory(){
    memory.size = machine_description.memory_size;
    Byte zero(0b00000000); // 8 bits
    memory.data.assign(memory.size, zero); // inicializa com zeros
}

void Machine::initializeGeneralRegisters(){ 
    uint16_t general_registers_size = machine_description.general_registers.size_of_general_registers;
    size_t data_size = general_registers_size/8;
    Binary data_zero(data_size, 0); // cria um zero Binary de 8, 16, 32, 64 ou 128 bits dependendo do tamanho do general_registers
    Binary identifier_byte(1,0); // Binary de 1 byte para criar o identificado:r binario
    Binary one(1,1);  // Binary de 1 byte para somar com o identificador binario
    int counter = 0;
    for (const auto reg:machine_description.general_registers.registers){
        general_registers.emplace(identifier_byte, GeneralRegister{RegisterInfo{"", general_registers_size},data_zero});
        id_to_binary.emplace(reg.identifier, identifier_byte);
        identifier_byte = BinaryUtils<Binary>::Add(identifier_byte, one);
        counter++;
        
    }
        
}
void Machine::initializeProgramCounter(){
    program_counter.info.size = machine_description.program_counter.size;
    program_counter.info.identifier = machine_description.program_counter.identifier;
    program_counter.address.assign(program_counter.info.size, 0);
        
}

void Machine::initializeFlagsRegister(){
    flags_register.info.size = machine_description.flags_register.size;
    flags_register.info.identifier = machine_description.flags_register.identifier;
    flags_register.flags.assign(flags_register.info.size, false);
}

void Machine::initializeInternalRegisters(){
    initializeProgramCounter();
    initializeFlagsRegister();
}
void Machine::initializeMachine(){
    initializeMemory();
    initializeGeneralRegisters();
    initializeInternalRegisters();

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

void Machine::loadInstructionSet(){
    //TODO
}
