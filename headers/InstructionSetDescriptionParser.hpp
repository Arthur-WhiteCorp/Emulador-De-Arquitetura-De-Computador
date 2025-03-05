#ifndef INSTRUCTION_SET_DESCRIPTION_PARSER_HPP
#define INSTRUCTION_SET_DESCRIPTION_PARSER_HPP

#include <nlohmann/json.hpp>
#include <JsonHandler.hpp>
#include <string>
#include <regex>
#include <iostream>
#include <InstructionSetDescription.h>
#include <JsonSchema.h>

class InstructionSetDescriptionParser {
    
public:
    InstructionSetDescriptionParser(std::string file_path);
    ~InstructionSetDescriptionParser();
private:
    bool success_parsing; // Checa a validade do JSON 
    JsonHandler handler;
    nlohmann::json machine_description_json; // JSON de descricao da maquina
    JsonSchema::JsonSchema json_schema; // Descrição da sintaxe valida do JSON
    InstructionSetDescription instruction_set_description; // Struct de descricao das instrucoes da maquina

    void initializeErrorFlags(); // inicializa as flags de erro
    void putMainFieldsInSchema(); // Coloca os campos principais do JSON na schema
    void checkAndFindSubFields(const JsonSchema::FieldDescription& schema, const std::string& sub_field_name, const std::string& parent_field_name, const nlohmann::json& json); 
    void checkAndFindField(const std::string& field_name); 
    void initializeArithmeticLogicFieldSchema();
    void initializeJumperFieldSchema();
    void initializeConditionalJumperFieldSchema();
    void initializeDataFieldSchema();
    void initializeJsonSchema();
    void checkIfFieldIsFound(const JsonSchema::FieldDescription& field_description, const std::string& parent_field_name = "none"); // Checa se o campo foi encontrado, "none" indica que é um campo principal
    void parseInstructionSetDescription();
   
};
#endif
