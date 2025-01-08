#include <MachineDescriptionParser.hpp>
#include <iostream>
#include <cstdlib> 

MachineDescriptionParser::MachineDescriptionParser(std::string machine_description_file_path) {
    openMachineDescriptionFile();
    turnMachineDescriptionFileToJson();
    closeMachineDescriptionFile();
    parseMachineDescription();
}

MachineDescriptionParser::~MachineDescriptionParser() {}    

void MachineDescriptionParser::openMachineDescriptionFile() {
    std::ifstream f("../testes/example.json");
    if (!f.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        exit(1);
    }
}

void MachineDescriptionParser::turnMachineDescriptionFileToJson() {
    // Implementation here
}

void MachineDescriptionParser::closeMachineDescriptionFile() {
    // Implementation here
}

void MachineDescriptionParser::parseMachineDescription() {
    // Implementation here
}

MachineDescription MachineDescriptionParser::getMachineDescription() {
    // Implementation here
}