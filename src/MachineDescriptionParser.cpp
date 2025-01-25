#include <MachineDescriptionParser.hpp>
#include <iostream>
#include <cstdlib> 
#include <nlohmann/json.hpp>
#include <cctype>
#include <typeinfo>


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
    


void MachineDescriptionParser::checkFieldValidity(const std::string& field) {
    std::string field_lower = lowerFieldName(field);

    if (expected_machine_description_fields.find(field_lower) == expected_machine_description_fields.end()) {
        std::cerr << "Field: " << field_lower << ", not recognized!" << std::endl;
        success_parsing = false;
    }else {
        if (recognized_fields.find(field_lower) != recognized_fields.end()) {
            std::cerr << "Field: " << field_lower << ", already recognized!" << "\n";
            std::cerr << "Please, delete the duplicate field." << std::endl;
            success_parsing = false;
            return;
        }

        recognized_fields.insert(field_lower);
    }
}

void MachineDescriptionParser::checkRequiredFields() {
    int size;
    size = recognized_fields.size();

    if (size != expected_machine_description_fields.size()){
        std::cerr << "Required fields not found!" << std::endl;
        success_parsing = false;

        for (auto field: expected_machine_description_fields){
            if (recognized_fields.find(field) == recognized_fields.end()){
                std::cerr << "Required field: " << field << ", not found!" << std::endl;
                success_parsing = false;
            }
        }
    }
}

void MachineDescriptionParser::checkRequiredFieldSintax(const nlohmann::json& field, const std::string& field_name) {
    if (field_name == "word_size") { checkWordSizeSintax(field); return; }
    //if (field == "register_address_size") { checkRegisterAddressSizeSintax(field); return; }
}

void MachineDescriptionParser::checkWordSizeSintax(const nlohmann::json& word_size_field) {
    auto word_size = word_size_field.get<uint16_t>();
    if (!word_size_field.is_number_unsigned()){
        success_parsing = false;
        std::cerr << "'word_size' must be an unsigned integer!" << std::endl;
    }

    if (word_size < 8 || word_size > 256 ) { // checa se word_size e menor que 8 ou maior que 256
        success_parsing = false;
        std::cerr << "'word_size' must be at least 8 and less than 257!" << std::endl;
    }

    if (!(word_size > 0 && (word_size & (word_size - 1)) == 0)){ // checa se word_size nao e potencia de 2
        success_parsing = false;
        std::cerr << "'word_size' must be a power of 2!" << std::endl;
    } 
}

void MachineDescriptionParser::parseMachineDescription() {
    if (!success_opening){ // checa se a abertura ou conversao foi bem sucedida
        return;
    }
    success_parsing = true;

    for (auto field = machine_description.begin(); field != machine_description.end(); field++) {
        checkFieldValidity(lowerFieldName(field.key()));
    }
    
    checkRequiredFields();

    for (auto recognized_field:recognized_fields) {
        checkRequiredFieldSintax(machine_description[recognized_field], recognized_field);
    }    
}