#ifndef MACHINE_DESCRIPTION_VALIDATOR_HPP
#define MACHINE_DESCRIPTION_VALIDATOR_HPP

#include <MachineDescription.h>

class MachineDescriptionValidator {

public:
    MachineDescriptionValidator(const MachineDescription& machine_description);
    ~MachineDescriptionValidator();
    bool isValid();
private:
    bool is_valid; // true se a descricao da maquina e valida
    const MachineDescription& machine_description;


    void initializeErrorFlags(); // inicializa os flags de erro
    void loadMachineDescription(MachineDescription machine_description_struct); // carrega a descricao da maquina
    void checkRegisterSize(std::string register_identifier, uint16_t register_size); // checa o tamanho do registro
    void checkRegistersSizes(); // checa o tamanho dos registos
    void checkRegistersIdentifiers(); // checa os identificadores dos registos
    void checkMemorySize(); // checa o tamanho da memoria
    void checkInstructionSize(); // checa o tamanho das instrucoes
    void checkRegisterAddressSize(); // checa o tamanho do endereco dos registos
    void validateInstructionAndRegisterAddressSize(); // checa se o tamanho da instrucao e do endereco dos registos e valido
    void checkMachineDescriptionValidity(); // checa a validade semantica da descricao da maquina
};

#endif 