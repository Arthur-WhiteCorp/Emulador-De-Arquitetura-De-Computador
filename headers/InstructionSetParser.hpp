#ifndef INSTRUCTION_SET_PARSER_HPP
#define INSTRUCTION_SET_PARSER_HPP

#include <nlohmann/json.hpp>
#include <JsonHandler.hpp>
#include <string>
#include <regex>
#include <iostream>

class InstructionSetParser {
public:
    InstructionSetParser();
    ~InstructionSetParser();
private:
    bool success_parsing; // Checa a validade do JSON 
    JsonHandler handler;
    nlohmann::json machine_description_json; // JSON de descricao da maquina
   
};
#endif
