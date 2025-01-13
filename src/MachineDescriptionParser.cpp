#include <MachineDescriptionParser.hpp>
#include <iostream>
#include <cstdlib> 
#include <nlohmann/json.hpp>
#include <cctype>


MachineDescriptionParser::MachineDescriptionParser(std::string machine_description_file_path) {
    openMachineDescriptionFile(machine_description_file_path);
    turnMachineDescriptionFileToJson();
    fillMachineDescriptionFields();
    parseMachineDescription();
}

MachineDescriptionParser::~MachineDescriptionParser() {
    closeMachineDescriptionFile();
}


MachineDescription MachineDescriptionParser::getMachineDescription() {
    // Implementation here
}

void MachineDescriptionParser::openMachineDescriptionFile(std::string machine_description_file_path) {
    this->machine_description_file_path = machine_description_file_path;
    machine_description_file.open(machine_description_file_path);
    if (!machine_description_file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        success_opening = false;
        return;
    }
    success_opening = true;
    return;
}

void MachineDescriptionParser::turnMachineDescriptionFileToJson() {
    if (!success_opening){ // checa se o passo anterior foi bem sucedido
        return;
    }
    
    try {
        machine_description = nlohmann::json::parse(machine_description_file);
        std::cout << "Conversion to JSON was successful!" << std::endl;
        return;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Failed to convert file to JSON: " << e.what() << std::endl;
        success_converting = false;
        return;
    }
}

void MachineDescriptionParser::closeMachineDescriptionFile() {
    if (!success_opening){ // checa se a abertura foi bem sucedida
        return;
    }

    machine_description_file.close();
    if (machine_description_file.is_open()) {
        std::cerr << "Failed to close the file: " << machine_description_file_path << std::endl;
        success_closing = false;
        return;  
    } else {
        std::cout << "Successfully closed the file: " << machine_description_file_path << std::endl;
        success_closing = true;
        return;
    }
}

void MachineDescriptionParser::fillMachineDescriptionFields() {
    expected_machine_description_fields.insert("word_size");
    expected_machine_description_fields.insert("register_address_size");
    expected_machine_description_fields.insert("instruction_size");
    expected_machine_description_fields.insert("memory_size");
    expected_machine_description_fields.insert("program_counter");   
    expected_machine_description_fields.insert("flags_register");
    expected_machine_description_fields.insert("general_registers");  
}

std::string MachineDescriptionParser::lowerFieldName(const std::string& field) {
    std::string lowerField;
    for (char c : field) {
        lowerField += std::tolower(c);
    }
    return lowerField;
}
    


bool MachineDescriptionParser::checkField(const std::string& field) {
    std::string field_lower = lowerFieldName(field);

    if (expected_machine_description_fields.find(field_lower) == expected_machine_description_fields.end()) {
        std::cerr << "Field: " << field_lower << ", not recognized!" << std::endl;
        return false;
    }

    std::cout << "Field: " << field_lower << ", found." << std::endl;

    return true;
}

void MachineDescriptionParser::parseMachineDescription() {
    if (!success_opening){ // checa se a abertura ou conversao foi bem sucedida
        return;
    }
    for (auto field = machine_description.begin(); field != machine_description.end(); field++) {
        success_parsing = checkField(lowerFieldName(field.key()));
    }
    return;
}