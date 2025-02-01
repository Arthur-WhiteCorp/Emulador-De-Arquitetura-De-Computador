#include <iostream>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <Machine.hpp>
#include <MachineDescriptionParser.hpp>
#include <MachineDescription.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <machine_description_file>" << std::endl;
        return 1;
    }

    std::string machine_description_file_path(argv[1]);

    std::unique_ptr<MachineDescriptionParser> machine_description_parser; 
    machine_description_parser = std::make_unique<MachineDescriptionParser>(machine_description_file_path);

    

    if (machine_description_parser->isSuccessful()){
        MachineDescription machine_description = machine_description_parser->getMachineDescription();
        std::cout << (int)machine_description.instruction_size << "\n";
        std::cout << machine_description.memory_size << "\n";
        std::cout << machine_description.program_counter.size << "\n";
        std::cout << machine_description.program_counter.identifier << "\n";
        std::cout << machine_description.flags_register.size << "\n";
        std::cout << machine_description.flags_register.identifier << "\n";
        std::cout << machine_description.general_registers.number_of_general_registers << "\n";
        std::cout << (unsigned int)machine_description.general_registers.size_of_general_registers << "\n";

        for (unsigned int i = 0; i < machine_description.general_registers.number_of_general_registers; i++){
            std::cout << machine_description.general_registers.registers[i].identifier << std::endl;
        }
    }

    return 0;
}
