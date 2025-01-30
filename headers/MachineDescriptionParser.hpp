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
    nlohmann::json machine_description_json; // JSON de descricao da maquina
    MachineDescription machine_description; // struct de descricao da maquina

    std::set<std::string> expected_machine_description_fields; // Campos do JSON de descricao da maquina
    std::set<std::string> recognized_fields; // Campos do JSON de descricao da maquina reconhecidos
    std::unordered_map<std::string, std::function<void(const nlohmann::json& field)>> field_fillers; // Funcoes que peenchem os campos da struct

    void openMachineDescriptionFile(std::string machine_description_file_path); // Abre o arquivo de descricao da maquina
    void turnMachineDescriptionFileToJson(); // Transforma o arquivo de descricao da maquina em um JSON
    void closeMachineDescriptionFile(); // Fecha o arquivo de descricao da maquina

    void fillExpectedMachineDescriptionFields(); // Preenche o array de campos do JSON
    void fillFieldFillers(); // Preenche o array de funcoes que preenchem os campos da struct
    std::string lowerFieldName(const std::string& field); // Transforma um campo em minusculo
    void checkFieldValidity(const std::string& field); // Verifica se um campo do JSON e valido
    void checkRequiredFields(); // Verifica se o JSON tem todos os campos necessarios
    bool checkSubField(const nlohmann::json& field, std::string sub_field_name); // Verifica se um subcampo do JSON existe;
    bool checkNumberOfExpectedSubFields(const nlohmann::json& field, unsigned int number_of_expected_sub_fields); // verifica o numero de subcampos esperados
    void checkRequiredFieldSyntax(const nlohmann::json& field, const std::string& field_name); // Verifica a Sintaxe dos campos do JSON
    void checkWordSizeSyntax(const nlohmann::json& word_size); // Verifica a Sintaxe do campo word_size
    void checkRegisterAddressSizeSyntax(const nlohmann::json& register_address_size); // Verifica a Sintaxe do campo register_address_size
    void checkInstructionSizeSyntax(const nlohmann::json& instruction_size); // Verifica a Sintaxe do campo instruction_size
    void checkMemorySizeSyntax(const nlohmann::json& memory_size); // Verifica a Sintaxe do campo memory_size
    void checkProgramCounterSyntax(const nlohmann::json& program_counter); // Verifica a Sintaxe do campo program_counter
    void checkFlagsRegisterSyntax(const nlohmann::json& flags_register); // Verifica a Sintaxe do campo flags_register
    void checkGeneralRegistersSyntax(const nlohmann::json& general_registers); // Verifica a Sintaxe do campo general_registers
    void fillMachineDescriptionField(std::string field_name); //Prrenche um campo da struct de descricao da maquina
    void handleIdPatternConstruction(const std::string& id_pattern , uint16_t number_of_general_registers); // Cria os ids dos registradores gerais com base no id_pattern
    void fillMachineDescription(); // Preenche a struct de descricao da maquina
    void parseMachineDescription(); // Realiza a leitura do json de descricao da maquina

};

#endif