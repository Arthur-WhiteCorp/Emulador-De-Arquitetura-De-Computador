#ifndef MACHINE_DESCRIPTION_H
#define MACHINE_DESCRIPTION_H

#include <cstdint>
#include <string>
#include <vector>

struct RegisterDescription
{    
    std::string identifier; // identificador do registro 
    uint16_t size; // tamanho do registro em bits
};


struct GeneralRegisterDescription {
    uint8_t number_of_registers;
    std::vector<RegisterDescription> registers;
};

struct MachineDescription
{
    uint8_t word_size; // tamanho de uma palavra em bits
    uint8_t register_address_size; // tamanho do endereço de um registro em bits
    uint8_t instruction_size; // tamanho da instrução em bits
    uint64_t  memory_size; // tamanho da memoria em bytes
    RegisterDescription program_counter; // registro que guarda o endereço da próxima instrução
    RegisterDescription flags_register; // registro que guarda as flags
    GeneralRegisterDescription general_registers; // descricao dos registros gerais
};




#endif