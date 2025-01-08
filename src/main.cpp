#include <iostream>
#include <fstream>
#include <memory>
#include <nlohmann/json.hpp>
#include <Machine.hpp>
#include <MachineDescriptionParser.hpp>

int main() {
    std::unique_ptr<MachineDescriptionParser> machine; 
    machine = std::make_unique<MachineDescriptionParser>("../testes/example.json");
    return 0;
}
