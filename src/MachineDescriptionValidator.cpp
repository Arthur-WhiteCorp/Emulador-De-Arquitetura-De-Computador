#include <MachineDescriptionValidator.hpp>
#include <MachineDescription.h>
#include <cstdint>
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

void MachineDescriptionValidator::checkWordSize(){
    if (machine_description.word_size < 8 || machine_description.word_size > 128 ) { // checa se word_size e menor que 8 ou maior que 256
        is_valid = false;
        std::cerr << "'word_size' must be at least 8 and less or equal than 128!" << std::endl;
    }

    if (!(machine_description.word_size > 0 // checa se word_size nao e potencia de 2
        && (machine_description.word_size & (machine_description.word_size - 1)) == 0)){ 
        is_valid = false;
        std::cerr << "'word_size' must be a power of 2!" << std::endl;
    } 
}

void MachineDescriptionValidator::checkGeneralRegistersSize(){
    if (machine_description.general_registers.size_of_general_registers > machine_description.word_size){
        is_valid = false;
        std::cerr << "'general_registers.size' must be less than or equal to word_size!" << std::endl;
    }
    if (!(machine_description.general_registers.size_of_general_registers > 0 // checa se word_size nao e potencia de 2
        && (machine_description.general_registers.size_of_general_registers & (machine_description.general_registers.size_of_general_registers - 1)) == 0)){ 
        is_valid = false;
        std::cerr << "'general_registers.size' must be a power of 2!" << std::endl;
    } 
}

void MachineDescriptionValidator::checkProgramCounterSize(){
    if (!(machine_description.program_counter.size > 0 // checa se word_size nao e potencia de 2
        && (machine_description.program_counter.size & (machine_description.program_counter.size - 1)) == 0)){ 
        is_valid = false;
        std::cerr << "'program_counter.size' must be a power of 2!" << std::endl;
    }
}

void MachineDescriptionValidator::checkFlagsRegisterSize(){
    // não tem o que checar o tamanho do flags register
}
void MachineDescriptionValidator::checkRegistersSizes(){
    checkGeneralRegistersSize();
    checkProgramCounterSize();
    checkFlagsRegisterSize();
}

void MachineDescriptionValidator::checkNumberOfGeneralRegisters(){
    uint8_t max_number_of_general_registers = pow(2, machine_description.register_address_size); // maximo 2^register_address_size
    if (machine_description.general_registers.number_of_general_registers > max_number_of_general_registers){
        is_valid = false;
        std::cerr << "'general_registers.number_of_registers' must be less than or equal to '2^register_address_size'!" << std::endl;
    }
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
        std::cerr << "'memory_size' must be less than or equal to 2^'word_size'!" << std::endl;    
    }

    if (machine_description.memory_size == 0){
        is_valid = false;
        std::cerr << "'memory_size' must be greater than 0!" << std::endl;
    }

    if (machine_description.memory_size % (machine_description.word_size/8) != 0){
        is_valid = false;
        std::cerr << "'memory_size' must be a multiple of 'word_size'!" << std::endl;
    }

}

void MachineDescriptionValidator::checkAluInstructionSize(){
    if (machine_description.alu_instruction_size > machine_description.word_size){
        is_valid = false;
        std::cerr << "'alu_instruction_size' must be less than or equal to 'word_size'!" << std::endl;
    }
}

void MachineDescriptionValidator::checkRegisterAddressSize(){
    if (machine_description.register_address_size > machine_description.word_size){
        is_valid = false;
        std::cerr << "'register_address_size' must be less than or equal to word_size!" << std::endl;
    }
}

void MachineDescriptionValidator::validateInstructionAndGeneralRegisterAddressSize(){
    std::uint16_t total_size = machine_description.register_address_size + machine_description.alu_instruction_size;

    if (total_size > machine_description.word_size){
        is_valid = false;
        std::cerr << "not enough space for alu instruction and register address!" << std::endl;
        std::cerr << "'register_address_size' + 'instruction_size' > word_size" << std::endl;

    }
}
void MachineDescriptionValidator::checkMachineDescriptionValidity(){
    checkWordSize();
    checkRegistersSizes();
    checkNumberOfGeneralRegisters();
    checkRegistersIdentifiers();
    checkMemorySize();
    checkAluInstructionSize();
    checkRegisterAddressSize();
    validateInstructionAndGeneralRegisterAddressSize();

    if (!is_valid){
        std::cerr << "Machine description is invalid!" << std::endl;
    }else{
        std::cout << "Machine description is valid!" << std::endl;
    }
}
