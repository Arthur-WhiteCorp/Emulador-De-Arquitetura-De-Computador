#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <MachineDescription.h>

class Machine{

using Binary = std::vector<uint8_t>;

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
    std::vector<Binary> data; // dados da memoria tem que ser um multiplo da palavra
};


public:
    MachineDescription machine_description; // descricao da maquina



    Machine(MachineDescription machine_description);
    ~Machine();
private:
    bool is_description_valid;


    Register program_counter; // registro que guarda o endereço da próxima instrução
    Register flags_register; // registro que guarda as flags
    std::vector<Register> general_registers; // registros gerais que o programa utiliza
    InstructionSet instruction_set; // lista de instruções
    Memory memory; // memória

    void initializeErrorFlags(); // inicializa os flags de erro
    void loadMachineDescription(MachineDescription machine_description_struct); // carrega a descricao da maquina
    void checkRegisterSize(std::string register_identifier, uint16_t register_size); // checa o tamanho do registro
    void checkRegistersSizes(); // checa o tamanho dos registos
    void checkMachineDescriptionValidity(); // checa a validade semantica da descricao da maquina
};

#endif

