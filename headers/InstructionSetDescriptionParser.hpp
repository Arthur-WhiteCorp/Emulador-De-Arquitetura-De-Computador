#ifndef INSTRUCTION_SET_DESCRIPTION_PARSER_HPP
#define INSTRUCTION_SET_DESCRIPTION_PARSER_HPP

#include <nlohmann/json.hpp>
#include <JsonHandler.hpp>
#include <string>
#include <regex>
#include <iostream>
#include <InstructionSetDescription.h>

class InstructionSetDescriptionParser {
public:
    InstructionSetDescriptionParser(std::string file_path);
    ~InstructionSetDescriptionParser();
private:
    bool success_parsing; // Checa a validade do JSON 
    JsonHandler handler;
    nlohmann::json machine_description_json; // JSON de descricao da maquina
    InstructionSetDescription instruction_set_description; // Struct de descricao das instrucoes da maquina

    void initializeErrorFlags(); // inicializa as flags de erro
    void parseInstructionSetDescription();
   
};
#endif
