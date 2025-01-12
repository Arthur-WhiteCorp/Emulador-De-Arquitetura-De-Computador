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
    bool success; // flag de erro 
    std::string machine_description_file_path;
    std::ifstream machine_description_file;
    nlohmann::json machine_description;
    bool openMachineDescriptionFile(std::string machine_description_file_path); // abre o arquivo de descricao da maquina
    bool turnMachineDescriptionFileToJson(bool success = true); // transforma o arquivo de descricao da maquina em um json
    bool closeMachineDescriptionFile(bool success = true ); // fecha o arquivo de descricao da maquina
    bool parseMachineDescription(bool success = true); // realiza a leitura do json de descricao da maquina
};

#endif