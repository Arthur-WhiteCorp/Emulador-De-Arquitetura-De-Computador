#include <BehaviorErrorListener.hpp>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>


void BehaviorErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const std::string& msg, std::exception_ptr e) {

    
    const std::string target_msg = std::string("mismatched input '") + offendingSymbol->getText() +  "' expecting {NUM, 'R', '('}";

    size_t token_index = offendingSymbol->getTokenIndex();
    size_t previos_token_index = token_index - 1;
    size_t string_size = instruction_behavior.size();
    size_t char_location;
    size_t error_location;
    antlr4::Token* last_valid_token = tokens.get(previos_token_index);
    

    size_t previous_token_location = last_valid_token->getCharPositionInLine(); 
   
    if (msg == target_msg) {
        std::cerr << "Syntax Error in: " << "Arithmetic_Logic::" << instruction_name << "::behavior::" << instruction_behavior << std::endl;
        std::cerr << "operator: " << tokens.get(previos_token_index)->getText() << " in position: " << previous_token_location;
        std::cerr << " expects NUMBER, REGISTER or Parenthesis Expression " <<  std::endl;

    }
    

    if (token_index > 0 && msg != target_msg) {

        std::cerr << "Syntax Error in: " << "Arithmetic_Logic::" << instruction_name << "::behavior::" << instruction_behavior << std::endl;
        std::cerr << "in position: " << previous_token_location << std::endl;
        std::cerr << msg << std::endl;

    }else if (msg != target_msg){
        std::cerr << "Syntax Error in: " << "Arithmetic_Logic::" << instruction_name << "::behavior::" << instruction_behavior << std::endl;
        std::cerr << "in position: " << previous_token_location << std::endl;
        std::cerr << msg << std::endl;
    }

}

