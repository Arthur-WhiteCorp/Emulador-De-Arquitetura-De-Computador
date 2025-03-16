#include <InstructionSetDescriptionValidator.hpp>
#include <InstructionPattern.h>
#include <regex.h>
#include <iostream>
#include <Tokens.hpp>

InstructionSetDescriptionValidator::InstructionSetDescriptionValidator(const InstructionSetDescription::InstructionSetDescription& instruction_set_description, const MachineDescription& machine_description): instruction_set_description(instruction_set_description), machine_description(machine_description){
    fillInstructionsPatterns();    
    validate();
}

InstructionSetDescriptionValidator::~InstructionSetDescriptionValidator(){


}

bool InstructionSetDescriptionValidator::isValid(){
    return is_valid; 
}

void InstructionSetDescriptionValidator::fillInstructionsPatterns(){
    const std::string& instruction_name = Tokens::token_patterns.at(Tokens::TokenType::INSTRUCTION_NAME);
    const std::string& register_id = Tokens::token_patterns.at(Tokens::TokenType::REGISTER_ID);
    const std::string& unsigned_num = Tokens::token_patterns.at(Tokens::TokenType::UNSIGNED_NUM); 
    const std::string& number = Tokens::token_patterns.at(Tokens::TokenType::NUMBER); 
    const std::string& register_id_or_number = Tokens::token_patterns.at(Tokens::TokenType::REGISTER_ID_OR_NUMBER);
    const std::string& my_operator =  Tokens::token_patterns.at(Tokens::TokenType::OPERATOR);
    const std::string& flags_register_pos = Tokens::token_patterns.at(Tokens::TokenType::FLAGS_REGISTER_POS); 


    const std::string syntax = instruction_name + "(\\s+" + register_id +  ")*"; 
    const std::string behavior = register_id + "\\s*=\\s*" + register_id_or_number + "(\\s*" + my_operator + "\\s*" + register_id_or_number + ")*"; 
  
    instructions_patterns["AL"] = InstructionPattern::InstructionPattern(
        syntax, 
        behavior 
    );

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

void InstructionSetDescriptionValidator::validateALInstructions(){
    const std::regex& syntax = instructions_patterns["AL"].syntax;
    const std::regex& behavior = instructions_patterns["AL"].behavior;
    const std::regex& flags_modification = *instructions_patterns["AL"].flags_modification;
    std::smatch match;
    bool is_matched;
    for (const auto& instruction : instruction_set_description.al_instructions){
        if (instruction.description.behavior != ""){
            matchField(instruction.description.behavior, behavior);
        } 
        matchField(instruction.description.syntax,syntax);

        return;
        
    } 
}

void InstructionSetDescriptionValidator::validateJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validateDataInstructions(){
    
}

void InstructionSetDescriptionValidator::validateConditionalJumperInstructions(){
    
}

void InstructionSetDescriptionValidator::validate(){
    std::cout << "começando validação" << std::endl;
    validateALInstructions(); 
}


