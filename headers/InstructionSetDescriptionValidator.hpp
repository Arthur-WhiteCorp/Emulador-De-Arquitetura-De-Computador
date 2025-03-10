#ifndef INSTRUCTION_SET_DESCRIPTION_VALIDATOR_HPP
#define INSTRUCTION_SET_DESCRIPTION_VALIDATOR_HPP

#include <InstructionSetDescription.h>
#include <MachineDescription.h>
#include <iostream>


class InstructionSetDescriptionValidator {
public:
    InstructionSetDescriptionValidator(const InstructionSetDescription::InstructionSetDescription& instruction_set_description, const MachineDescription& machine_description);
    ~InstructionSetDescriptionValidator();
    bool isValid();
private:
    bool validate(const InstructionSetDescription::InstructionSetDescription& instruction_set_description);
    const MachineDescription& machine_description;
    const InstructionSetDescription::InstructionSetDescription& instruction_set_description;

};
#endif
