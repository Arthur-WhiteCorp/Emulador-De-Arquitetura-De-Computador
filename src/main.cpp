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
        std::unique_ptr<Machine> machine;
        machine = std::make_unique<Machine>(machine_description);
    }
    return 0;
}
