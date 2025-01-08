#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <MachineDescription.h>

class Machine{

using Binary = std::vector<bool>;

struct Instruction{
    Binary code; // código da instrução em binario

};

struct Word{
    Binary data;
};

struct Register{
    std::string identifier; // identificador do registro 
    uint16_t size; // tamanho do registro em bits
    Binary data; // dados do registro
};

public:
    MachineDescription description; // descricao da maquina



    Machine(/* args */);
    ~Machine();
private:
  
    Register program_counter; // registro que guarda o endereço da próxima instrução
    Register flags_register; // registro que guarda as flags
    std::vector<Register> general_registers; // registros gerais que o programa utiliza
    std::vector<Instruction> instruction_set; // lista de instruções
    std::vector<Word> memory; // memória

};

#endif

