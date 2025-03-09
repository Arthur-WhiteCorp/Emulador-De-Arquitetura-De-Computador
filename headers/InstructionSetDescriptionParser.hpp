#ifndef INSTRUCTION_SET_DESCRIPTION_PARSER_HPP
#define INSTRUCTION_SET_DESCRIPTION_PARSER_HPP

#include <nlohmann/json.hpp>
#include <JsonHandler.hpp>
#include <string>
#include <InstructionSetDescription.h>
#include <JsonSchema.h>

class InstructionSetDescriptionParser {
    
public:
    InstructionSetDescriptionParser(std::string file_path);
    ~InstructionSetDescriptionParser();

    InstructionSetDescription::InstructionSetDescription getInstructionSetDescription();
    bool isSuccessful();
private:
    bool success_parsing; // Checa a validade do JSON 
    JsonHandler handler;
    nlohmann::json instruction_set_description_json; // JSON de descricao da maquina
    JsonSchema::JsonSchema json_schema; // Descrição da sintaxe valida do JSON
    InstructionSetDescription::InstructionSetDescription instruction_set_description; // Struct de descricao das instrucoes da maquina
    std::unordered_map<std::string, std::function<void(const nlohmann::json& field, const std::string& instruction_name)>> field_fillers; // Funcoes que peenchem os campos da struct
     
    void fillFieldFillers(); // Preenche o map de funcoes que preenchem os campos da struct
    void initializeErrorFlags(); // inicializa as flags de erro
    void putMainFieldsInSchema(); // Coloca os campos principais do JSON na schema
    void initializeArithmeticLogicFieldSchema();
    void initializeJumperFieldSchema();
    void initializeConditionalJumperFieldSchema();
    void initializeDataFieldSchema();
    void initializeJsonSchema();
    void checkField(const std::string& field_name); 
    void checkSubFields(const JsonSchema::FieldDescription& schema, const std::string& sub_field_name, const std::string& parent_field_name, const nlohmann::json& json); 
    void checkForMissingFields();
    void checkForMissingSubFields(const JsonSchema::FieldDescription& field_description);
    void fillInstructionSetDescriptionField(std::string field_name); //Prenche um campo da struct de descricao das instrucoes
    void parseInstructionSetDescription();
    void fillInstructionSetDescription(); // prrenche a struct de descricao das instrucoes 
};
#endif
