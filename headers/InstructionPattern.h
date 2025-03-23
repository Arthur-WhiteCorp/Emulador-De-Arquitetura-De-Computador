#ifndef INSTRUCTION_PATTERN_H
#define INSTRUCTION_PATTERN_H


#include <regex>
#include <unordered_map>
#include <memory>

namespace InstructionPattern {

    struct InstructionPattern {
        std::regex syntax;
        std::unique_ptr<std::regex> behavior; // opcional para AL 
        
        std::unique_ptr<std::regex> activation; // para Conditional_Jumper
        std::unique_ptr<std::regex> flags; // para Conditional_Jumper
        std::unique_ptr<std::regex> flags_modification; // para Arithmetic_Logic
        
        std::unordered_map<std::string, std::string> reserved_words; // palavras reservadas
        
        InstructionPattern() = default;
        InstructionPattern(std::string syntax ) : syntax(syntax) {};
    };



    using InstructionsPatterns = std::unordered_map<std::string, InstructionPattern>;
}

#endif
