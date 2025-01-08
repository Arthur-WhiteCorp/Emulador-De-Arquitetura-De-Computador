#ifndef MACHINE_DESCRIPTION_PARSER_HPP
#define MACHINE_DESCRIPTION_PARSER_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <MachineDescription.h>
#include <iostream>

class  MachineDescriptionParser{
public:
    MachineDescriptionParser(std::string machine_description_file_path);
    ~MachineDescriptionParser();
    MachineDescription getMachineDescription();
private:
    std::ifstream machine_description_file;
    nlohmann::json machine_description;
    void openMachineDescriptionFile(); // abre o arquivo de descricao da maquina
    void turnMachineDescriptionFileToJson(); // transforma o arquivo de descricao da maquina em um json
    void closeMachineDescriptionFile(); // fecha o arquivo de descricao da maquina
    void parseMachineDescription(); // realiza a leitura do json de descricao da maquina
};

#endif