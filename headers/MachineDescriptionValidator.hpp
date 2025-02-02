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
    bool checkPrefixesEquality(const std::string& register_identifier_a, const std::string& register_identifier_b, std::size_t prefix_size); // checa os prefixos dos identificadores dos registos
    void checkRegistersIdentifiers(); // checa os identificadores dos registos
    void checkMachineDescriptionValidity(); // checa a validade semantica da descricao da maquina
};

#endif 