#include "ANTLRInputStream.h"
#include "CommonTokenStream.h"
#include <InstructionSetDescriptionValidator.hpp>
#include <InstructionSetDescription.h>
#include <InstructionPattern.h>
#include <regex.h>
#include <iostream>
#include <RegexPatterns.hpp>
#include <unordered_map>
#include <BehaviorLexer.h>
#include <BehaviorParser.h>

InstructionSetDescriptionValidator::InstructionSetDescriptionValidator(const InstructionSetDescription::InstructionSetDescription& instruction_set_description, const MachineDescription& machine_description): instruction_set_description(instruction_set_description), machine_description(machine_description){
    fillInstructionsPatterns();       
    validateRegexFields();
    validateGrammarFields();
}

InstructionSetDescriptionValidator::~InstructionSetDescriptionValidator(){


}

bool InstructionSetDescriptionValidator::isValid(){
    return is_valid; 
}

void InstructionSetDescriptionValidator::fillInstructionsPatterns(){
    const std::string& instruction_name = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::INSTRUCTION_NAME);
    const std::string& register_id = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::REGISTER_ID);
    const std::string& unsigned_num = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::UNSIGNED_NUM); 
    const std::string& number = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::NUMBER); 
    const std::string& register_id_or_number = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::REGISTER_ID_OR_NUMBER);
    const std::string& binary_operator =  RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::BINARY_OPERATOR);
    const std::string& flags_register_pos = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::FLAGS_REGISTER_POS); 
    const std::string& negation = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::NEGATION);
    const std::string& conditional_operator = RegexPatterns::regex_patterns.at(RegexPatterns::PatternType::CONDITIONAL_OPERATOR);

    const std::string syntax = instruction_name + "(\\s+" + register_id +  ")*"; 
     
    instructions_patterns["AL"] = InstructionPattern::InstructionPattern(syntax);

    //std::string flags_modification = 
    
    instructions_patterns["AL"].flags_modification = std::make_unique<std::regex>(R"((\()(\w+)(\))(\?))");
    instructions_patterns["AL"].reserved_words["MAX"] = "MAX";
    instructions_patterns["AL"].reserved_words["MIN"] = "MIN";
    instructions_patterns["AL"].reserved_words["flags_register"] = "flags_register[n]";

    instructions_patterns["Data"];
    instructions_patterns["Condional_Jumper"];
    instructions_patterns["Jumper"];
    instructions_patterns["Input_Output"];
}


void InstructionSetDescriptionValidator::matchField(const std::string& input, const std::regex& regex){
    std::regex_iterator<std::string::const_iterator> it(input.begin(), input.end(), regex);
    std::regex_iterator<std::string::const_iterator> end_it;

    std::string::const_iterator last_end = input.begin();

    std::cout << "avaliando: " << std::endl;
    std::cout << input << std::endl;
    for (; it != end_it; ++it) {
        std::smatch match = *it;

        if (match.prefix().length() > 0) {
            std::cerr << "Unexpected text before last valid match: " << match.prefix() << std::endl;
            is_valid = false;
        }

        last_end = match.suffix().first;
    }

    if (last_end != input.end()) {
        std::cout << "Unexpected text after last valid match: " << std::string(last_end, input.end()) << std::endl;
        is_valid = false;
    }


}

void InstructionSetDescriptionValidator::validateRegexALInstructions(){
    const std::regex& syntax = instructions_patterns["AL"].syntax;
    const std::regex& flags_modification = *instructions_patterns["AL"].flags_modification;
    std::smatch match;
    bool is_matched;
    for (const auto& instruction : instruction_set_description.al_instructions){
        matchField(instruction.description.syntax,syntax);

        return;
        
    } 
}

void InstructionSetDescriptionValidator::validateRegexJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validateRegexDataInstructions(){
    
}

void InstructionSetDescriptionValidator::validateRegexConditionalJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validateRegexFields(){
    std::cout << "começando validação Regex" << std::endl;
    validateRegexALInstructions(); 
}

void InstructionSetDescriptionValidator::validateGrammarALInstructions(){
    for (const auto& instruction : instruction_set_description.al_instructions){
        if (instruction.description.behavior != InstructionSetDescription::EMPTY_STRING){
            antlr4::ANTLRInputStream input(instruction.description.behavior);
            BehaviorLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            tokens.fill();
            BehaviorParser parser(&tokens);
            antlr4::tree::ParseTree* tree = parser.root();
            std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
        }
    }  
}

void InstructionSetDescriptionValidator::validateGrammarFields(){
    std::cout << "começando validação gramatical" << std::endl;
    validateGrammarALInstructions();
}
