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


struct Instruction{
    Binary code; // código da instrução em binario
};

struct RegisterInfo{
    std::string identifier; // identificador do registro 
    uint16_t size; // tamanho do registro em bits
};

struct GeneralRegister{
    RegisterInfo info;
    Binary data;
};

struct ProgramCounter{
    RegisterInfo info;
    Binary address;
};

using Flags = std::vector<bool>;
struct FlagsRegister{
    RegisterInfo info;
    Flags flags;
};


struct Memory
{   
    uint64_t size; // tamanho da memoria em bytes
    std::vector<Byte> data; // dados da memoria tem que ser um multiplo da palavra
};

using InstructionSet = std::vector<Instruction>;
using RegisterIdToBinaryMap = std::unordered_map<std::string, Binary>;
using GeneralRegistersMap = std::unordered_map<Binary, GeneralRegister, BinaryHash, BinaryEqual>;
// falta testar meu map
public:
    Machine(MachineDescription machine_description);
    ~Machine();
private:
    const MachineDescription machine_description; // descricao da maquina
    std::unique_ptr<MachineDescriptionValidator> machine_description_validator; // validador da descricao da maquina
    ProgramCounter program_counter; // registro que guarda o endereço da próxima instrução
    FlagsRegister flags_register; // registro que guarda as flags
    RegisterIdToBinaryMap id_to_binary; // map de identificador para binario
    GeneralRegistersMap general_registers; // registradores gerais
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

