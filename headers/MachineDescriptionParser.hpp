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

public:
    MachineDescriptionParser(std::string machine_description_file_path);
    ~MachineDescriptionParser();
    MachineDescription getMachineDescription(); // Retorna a descricao da maquina
private:

    bool success_opening; // Checa se o arquivo de descricao da maquina foi aberto ou convertido para JSON
    bool success_converting; // Checa se o arquivo dedescricao da maquina foi convertido para JSON
    bool success_parsing; // Checa a validade do JSON 
    bool success_closing; // Checa se o arquivo de descricao da maquina foi fechado
    
    std::string machine_description_file_path; // Caminho do arquivo de descricao da maquina
    std::ifstream machine_description_file; // Arquivo de descricao da maquina
    nlohmann::json machine_description; // JSON de descricao da maquina
    std::set<std::string> expected_machine_description_fields; // Campos do JSON de descricao da maquina
    std::set<std::string> recognized_fields; // Campos do JSON de descricao da maquina reconhecidos

    void openMachineDescriptionFile(std::string machine_description_file_path); // Abre o arquivo de descricao da maquina
    void turnMachineDescriptionFileToJson(); // Transforma o arquivo de descricao da maquina em um JSON
    void closeMachineDescriptionFile(); // Fecha o arquivo de descricao da maquina

    void fillMachineDescriptionFields(); // Preenche o array de campos do JSON
    std::string lowerFieldName(const std::string& field); // Transforma um campo em minusculo
    void checkFieldValidity(const std::string& field); // Verifica se um campo do JSON e valido
    void checkRequiredFields(); // Verifica se o JSON tem todos os campos necessarios
    void checkRequiredFieldSintax(const nlohmann::json& field, const std::string& field_name); // Verifica a sintaxe dos campos do JSON
    void checkWordSizeSintax(const nlohmann::json& word_size); // Verifica a sintaxe do campo word_size
    void parseMachineDescription(); // Realiza a leitura do json de descricao da maquina

};

#endif