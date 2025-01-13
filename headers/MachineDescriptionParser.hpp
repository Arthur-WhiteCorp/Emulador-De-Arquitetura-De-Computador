#ifndef MACHINE_DESCRIPTION_PARSER_HPP
#define MACHINE_DESCRIPTION_PARSER_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <MachineDescription.h>
#include <iostream>
#include <set>

class  MachineDescriptionParser{

    enum MachineDescriptionField { // Campos do JSON de descricao da maquina
        WORD_SIZE,
        REGISTER_ADDRESS_SIZE,
        INSTRUCTION_SIZE,
        MEMORY_SIZE,
        PROGRAM_COUNTER,
        FLAGS_REGISTER,
        GENERAL_REGISTERS
    };



public:
    MachineDescriptionParser(std::string machine_description_file_path);
    ~MachineDescriptionParser();
    MachineDescription getMachineDescription(); // Retorna a descricao da maquina
private:
    bool success; // Flag de erro 
    std::string machine_description_file_path; // Caminho do arquivo de descricao da maquina
    std::ifstream machine_description_file; // Arquivo de descricao da maquina
    nlohmann::json machine_description; // JSON de descricao da maquina
    std::set<MachineDescriptionField> expected_machine_description_fields; // Campos do JSON de descricao da maquina

    bool openMachineDescriptionFile(std::string machine_description_file_path); // Abre o arquivo de descricao da maquina
    bool turnMachineDescriptionFileToJson(bool success = true); // Transforma o arquivo de descricao da maquina em um JSON
    void fillMachineDescriptionFields(); // Preenche o array de campos do JSON
    bool parseMachineDescription(bool success = true); // Realiza a leitura do json de descricao da maquina
    bool checkField(std::string field); // Verifica se um campo do JSON existe
    bool closeMachineDescriptionFile(bool success = true ); // Fecha o arquivo de descricao da maquina


};

#endif