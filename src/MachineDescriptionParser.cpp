#include <MachineDescriptionParser.hpp>
#include <iostream>
#include <cstdlib> 
#include <nlohmann/json.hpp>

MachineDescriptionParser::MachineDescriptionParser(std::string machine_description_file_path) {
    success = openMachineDescriptionFile(machine_description_file_path);
    turnMachineDescriptionFileToJson(success);
    parseMachineDescription(success);
}

MachineDescriptionParser::~MachineDescriptionParser() {
    closeMachineDescriptionFile(success);
}    

bool MachineDescriptionParser::openMachineDescriptionFile(std::string machine_description_file_path) {
    this->machine_description_file_path = machine_description_file_path;
    machine_description_file.open(machine_description_file_path);
    if (!machine_description_file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return false;
    }

    return true;
}

bool MachineDescriptionParser::turnMachineDescriptionFileToJson(bool success) {
    if (!success){ // checa se o passo anterior foi bem sucedido
        return false;
    }
    
    try {
        machine_description = nlohmann::json::parse(machine_description_file);
        std::cout << "Conversion to JSON was successful!" << std::endl;
        return true;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Failed to convert file to JSON: " << e.what() << std::endl;
        return false;
    }
}

bool MachineDescriptionParser::closeMachineDescriptionFile(bool success) {
    if (!success){ // checa se o passo anterior foi bem sucedido
        return false;
    }

    machine_description_file.close();
    if (machine_description_file.is_open()) {
        std::cerr << "Failed to close the file: " << machine_description_file_path << std::endl;
        return false;  
    } else {
        std::cout << "Successfully closed the file: " << machine_description_file_path << std::endl;
        return true;
    }
}

bool MachineDescriptionParser::parseMachineDescription(bool success) {
    if (!success){ // checa se o passo anterior foi bem sucedido
        return false;
    }




    return true;
}

MachineDescription MachineDescriptionParser::getMachineDescription() {
    // Implementation here
}