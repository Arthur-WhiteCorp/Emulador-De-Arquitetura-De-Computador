#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <bitset>

class Machine{

using Binary = std::vector<bool>;

struct Register
{
    uint16_t size; // tamanho do registro em bits
    std::string identifier; // identificador do registro 

};

struct Instruction{
    Binary code; // código da instrução em binario

};

struct Word{
    Binary data;
};

public:
    Machine(/* args */);
    ~Machine();
private:
    uint16_t word_size; // tamanho da palavra em bits
    uint8_t register_address_size; // tamanho do endereço de um registro em bits
    uint8_t instruction_size; // tamanho da instrução em bits
    uint64_t  memory_size; // tamanho da memoria em bytes
    Register program_counter; // registro que guarda o endereço da próxima instrução
    Register flags_register; // registro que guarda as flags
    std::vector<Register> general_registers; // registros gerais que o programa utiliza
    std::vector<Instruction> instruction_set; // lista de instruções
    std::vector<Word> memory; // memória

};

#endif

