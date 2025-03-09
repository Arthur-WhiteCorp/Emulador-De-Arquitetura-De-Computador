#ifndef INSTRUCTION_SET_DESCRIPTION_VALIDATOR_HPP
#define INSTRUCTION_SET_DESCRIPTION_VALIDATOR_HPP

#include <InstructionSetDescription.h>
#include <iostream>


class InstructionSetDescriptionValidator {
public:
    InstructionSetDescriptionValidator();
    ~InstructionSetDescriptionValidator();
    bool isInstructionSetDescriptionValid(const InstructionSetDescription::InstructionSetDescription& instruction_set_description);
private:

    bool validate(const InstructionSetDescription::InstructionSetDescription& instruction_set_description);
};
#endif
