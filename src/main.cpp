#include <iostream>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <Machine.hpp>
#include <MachineDescriptionParser.hpp>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <machine_description_file>" << std::endl;
        return 1;
    }

    std::string machine_description_file_path(argv[1]);

    std::unique_ptr<MachineDescriptionParser> machine; 
    machine = std::make_unique<MachineDescriptionParser>(machine_description_file_path);

    return 0;
}
