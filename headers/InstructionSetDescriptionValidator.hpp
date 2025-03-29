#ifndef INSTRUCTION_SET_DESCRIPTION_VALIDATOR_HPP
#define INSTRUCTION_SET_DESCRIPTION_VALIDATOR_HPP

#include <InstructionSetDescription.h>
#include <MachineDescription.h>
#include <InstructionPattern.h>

class InstructionSetDescriptionValidator {
    
public:
   InstructionSetDescriptionValidator(const InstructionSetDescription::InstructionSetDescription& instruction_set_description, const MachineDescription& machine_description);
   ~InstructionSetDescriptionValidator();
   bool isValid();

private:  
   bool is_valid;
   InstructionPattern::InstructionsPatterns instructions_patterns;
    
   void fillInstructionsPatterns();

   void matchField(const std::string& input, const std::regex& regex, const std::string& instruction_name, const std::string& field_name, const std::string& instruction_type ); // checa a o formato do campo e printa formatos errados

   void validateALInstructionSemantic(); // validação semantica de uma instrução
   void validateRegexALInstructions();
   void validateRegexDataInstructions();
   void validateRegexJumperInstructions();
   void validateRegexConditionalJumperInstructions();
   void validateRegexInputOutputInstructions();
   void syntaxRegexError(const std::regex& regex, const std::string& input);
   void showRegexError(const std::string& instruction_type, const std::regex& regex, const std::string& input);
   void validateRegexFields(); // valida os campos que podem ser expressos em regex chamando as funçoes acima
   void validateGrammarALInstructions();
   void validateGrammarFields();
   const MachineDescription& machine_description;
   const InstructionSetDescription::InstructionSetDescription& instruction_set_description;

};
#endif
