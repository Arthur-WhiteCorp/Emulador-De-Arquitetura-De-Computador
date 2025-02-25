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
    JsonSchema json_schema; // Descrição da sintaxe valida do JSON
    InstructionSetDescription instruction_set_description; // Struct de descricao das instrucoes da maquina
    

    void initializeErrorFlags(); // inicializa as flags de erro
    void checkRequiredFields();
    void fillExpectedInstructionSetDescriptionFields(); // LA, JUMPER, CONDICIONAL_JUMPER, DATA, INPUT_OUTPUT
    void checkInstructionSetDescriptionJsonStructure(); // Checa se possui os campos e subcampos corretos
    void parseInstructionSetDescription();
   
};
#endif
