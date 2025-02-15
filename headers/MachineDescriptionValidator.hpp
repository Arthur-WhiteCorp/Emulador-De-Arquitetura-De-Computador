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
    void checkWordSize(); // checa o tamanho da palavra
    void checkGeneralRegistersSize(); // checa o tamanho dos registos gerais
    void checkProgramCounterSize(); // checa o tamanho do Program Counter
    void checkFlagsRegisterSize(); // checa o tamanho do Flags Register
    void checkRegistersSizes(); // checa o tamanho dos registos
    void checkNumberOfGeneralRegisters(); // checha o numero de registos gerais (máximo 2^geretal_re)
    void checkRegistersIdentifiers(); // checa os identificadores dos registos
    void checkMemorySize(); // checa o tamanho da memoria
    void checkAluInstructionSize(); // checa o tamanho das instrucoes
    void checkRegisterAddressSize(); // checa o tamanho do endereco dos registos
    void validateInstructionAndGeneralRegisterAddressSize(); // checa se o tamanho da instrucao e do endereco dos registos e valido
    void checkMachineDescriptionValidity(); // checa a validade semantica da descricao da maquina
};

#endif 
