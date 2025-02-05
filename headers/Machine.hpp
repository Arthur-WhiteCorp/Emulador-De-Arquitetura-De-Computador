#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <MachineDescription.h>
#include <MachineDescriptionValidator.hpp>
#include <memory>
#include <unordered_map>
#include <BinaryUtils.hpp>


class Machine{

using Byte = uint8_t;
using Binary = std::vector<Byte>; // tamanho minimo 8 bits (1 byte)

struct Instruction{
    Binary code; // código da instrução em binario

};

using InstructionSet = std::vector<Instruction>;

struct Register{
    std::string identifier; // identificador do registro 
    uint16_t size; // tamanho do registro em bits
    Binary data; // dados do registro
};

struct Memory
{   
    uint64_t size; // tamanho da memoria em bytes
    std::vector<Byte> data; // dados da memoria tem que ser um multiplo da palavra
};

public:
    Machine(MachineDescription machine_description);
    ~Machine();
private:
    const MachineDescription machine_description; // descricao da maquina
    std::unique_ptr<MachineDescriptionValidator> machine_description_validator; // validador da descricao da maquina
    Register program_counter; // registro que guarda o endereço da próxima instrução
    Register flags_register; // registro que guarda as flags
    std::unordered_map<std::string, Register> general_registers;
    InstructionSet instruction_set; // lista de instruções
    Memory memory; // memória

    void initializeErrorFlags(); // inicializa os flags de erro
    void loadMachineDescription(MachineDescription machine_description_struct); // carrega a descricao da maquina
    bool isMachineDescriptionValid(const MachineDescription& machine_description); // checa a validade da descricao da maquina
    void initializeMemory(); // inicializa a memória
    void initializeInteralRegisters(); // inicializa os registradores internos (pc e flags)
    void initializeGeneralRegisters(); // inicializa os registradores gerais
    void initializeMachine(); // cria a maquina baseado na descricao da maquina
};

#endif

