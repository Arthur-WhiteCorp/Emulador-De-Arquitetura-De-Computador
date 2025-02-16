#ifndef INSTRUCTION_SET_PARSER_HPP
#define INSTRUCTION_SET_PARSER_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <regex>
#include <iostream>

class InstructionSetParser {
public:
    InstructionSetParser();
    ~InstructionSetParser();
private:
    bool success_opening; // Checa se o arquivo de descricao da maquina foi aberto ou convertido para JSON
    bool success_converting; // Checa se o arquivo dedescricao da maquina foi convertido para JSON
    bool success_parsing; // Checa a validade do JSON 
    bool success_closing; // Checa se o arquivo de descricao da maquina foi fechado
    
};
#endif
