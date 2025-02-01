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

struct GeneralRegisterDescription{
    std::string identifier; // identificador do registro
};

struct GeneralRegistersDescription {
    uint16_t number_of_general_registers; // máximo de 2^16 ou o limite de register_address_size
    uint16_t size_of_general_registers; // máximo de 2^16 ou o limite de word_size
    std::string id_pattern;
    std::vector<GeneralRegisterDescription> registers;
};

struct MachineDescription
{
    uint16_t word_size; // tamanho de uma palavra em bits, minimo 8 bits, sempre multiplo de 8
    uint8_t register_address_size; // tamanho do endereço de um registro em bits
    uint8_t instruction_size; // tamanho da instrução em bits
    uint64_t  memory_size; // tamanho da memoria em bytes
    RegisterDescription program_counter; // registro que guarda o endereço da próxima instrução
    RegisterDescription flags_register; // registro que guarda as flags
    GeneralRegistersDescription general_registers; // descricao dos registros gerais
    MachineDescription() {} // construtor padrão
    MachineDescription(const MachineDescription& other);
    MachineDescription& operator=(const MachineDescription& other);
};




#endif