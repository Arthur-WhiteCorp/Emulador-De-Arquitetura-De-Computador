#include <MachineDescriptionParser.hpp>
#include <iostream>
#include <cstdlib> 
#include <nlohmann/json.hpp>
#include <cctype>
#include <typeinfo>


MachineDescriptionParser::MachineDescriptionParser(std::string machine_description_file_path) {
    openMachineDescriptionFile(machine_description_file_path);
    turnMachineDescriptionFileToJson();
    fillExpectedMachineDescriptionFields();
    fillFieldFillers(); // nome engraçado
    parseMachineDescription();
}

MachineDescriptionParser::~MachineDescriptionParser() {
    closeMachineDescriptionFile();
}


MachineDescription MachineDescriptionParser::getMachineDescription() {
    return machine_description;
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
        machine_description_json = nlohmann::json::parse(machine_description_file);
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

void MachineDescriptionParser::fillExpectedMachineDescriptionFields() {
    expected_machine_description_fields.insert("word_size");
    expected_machine_description_fields.insert("register_address_size");
    expected_machine_description_fields.insert("instruction_size");
    expected_machine_description_fields.insert("memory_size");
    expected_machine_description_fields.insert("program_counter");   
    expected_machine_description_fields.insert("flags_register");
    expected_machine_description_fields.insert("general_registers");  
}

void MachineDescriptionParser::handleIdPatternConstruction(const std::string& id_pattern, uint16_t number_of_general_registers) {

    GeneralRegisterDescription general_register_description;

    for (int i = 0; i < number_of_general_registers; i++) {
        general_register_description.identifier = id_pattern + std::to_string(i);
        machine_description.general_registers.registers[i] = general_register_description;        
    }
}

void MachineDescriptionParser::fillFieldFillers() {
    field_fillers["program_counter"] = [&](const nlohmann::json& field) {
        machine_description.program_counter.identifier = field["id"].get<std::string>();
        machine_description.program_counter.size = field["size"].get<uint16_t>();
    };

    field_fillers["flags_register"] = [&](const nlohmann::json& field) {
        machine_description.flags_register.identifier = field["id"].get<std::string>();
        machine_description.flags_register.size = field["size"].get<uint16_t>();
    };

    field_fillers["general_registers"] = [&](const nlohmann::json& field) {
        machine_description.general_registers.number_of_general_registers = field["number_of_registers"].get<uint16_t>();
        machine_description.general_registers.size_of_general_registers = field["size"].get<uint16_t>();
        machine_description.general_registers.id_pattern = field["id_pattern"].get<std::string>();
        machine_description.general_registers.registers.reserve(machine_description.general_registers.number_of_general_registers);
        handleIdPatternConstruction(machine_description.general_registers.id_pattern, machine_description.general_registers.number_of_general_registers);
    };

    field_fillers["memory_size"] = [&](const nlohmann::json& field) {
        machine_description.memory_size = field.get<uint64_t>();
    };

    field_fillers["instruction_size"] = [&](const nlohmann::json& field) {
        machine_description.instruction_size = field.get<uint8_t>();
    };

    field_fillers["register_address_size"] = [&](const nlohmann::json& field) {
        machine_description.register_address_size = field.get<uint8_t>();
    };

    field_fillers["word_size"] = [&](const nlohmann::json& field) {
        machine_description.word_size = field.get<uint16_t>();
    };
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
        for (auto recognized_field:recognized_fields){
            if (lowerFieldName(recognized_field) == field_lower){
                std::cerr << "Field: " << field_lower << ", already recognized!" << "\n";
                std::cerr << "Please, delete the duplicate field: ";
                std::cerr << "'" << field << "'" << std::endl;
                success_parsing = false;
                return;
            }
        }
        recognized_fields.insert(field);
    }
}

void MachineDescriptionParser::checkRequiredFields() {
    int size;
    bool is_found = false;
    size = recognized_fields.size();

    if (size < expected_machine_description_fields.size()){
        std::cerr << "Required fields not found!" << std::endl;
        success_parsing = false;

        for (auto field: expected_machine_description_fields){
            for (auto recognized_field: recognized_fields){
                if (lowerFieldName(recognized_field) == field){
                    is_found = true;
                    break;
                }
            }
            if (is_found == false){
                std::cerr << "Required field: " << field << ", not found!" << std::endl;
                is_found = false;
            }
        }
    }
}

bool MachineDescriptionParser::checkSubField(const nlohmann::json& field, std::string sub_field_name) {
    if (!field.contains(sub_field_name)) {
        std::cerr << "Required sub field: " << sub_field_name << ", not found!" << std::endl;
        success_parsing = false;
        return false;
    }else{
        return true;
    }
}

bool MachineDescriptionParser::checkNumberOfExpectedSubFields(const nlohmann::json& field,  unsigned int number_of_expected_sub_fields) {
    if (field.size() != number_of_expected_sub_fields) {
        std::cerr << "Number of expected sub fields: " << number_of_expected_sub_fields << std::endl;
        std::cerr << "Number of found sub fields: " << field.size() << std::endl;
        success_parsing = false;
        return false;
    }else{
        return true;
    }
}

void MachineDescriptionParser::checkRequiredFieldSyntax(const nlohmann::json& field, const std::string& field_name) {
    std::string field_name_lower = lowerFieldName(field_name);
    if (field_name_lower == "word_size") { checkWordSizeSyntax(field); return; }
    if (field_name_lower == "register_address_size") { checkRegisterAddressSizeSyntax(field); return; }
    if (field_name_lower == "instruction_size") { checkInstructionSizeSyntax(field); return; }
    if (field_name_lower == "memory_size") { checkMemorySizeSyntax(field); return; }
    if (field_name_lower == "program_counter") { checkProgramCounterSyntax(field); return; }   
    if (field_name_lower == "flags_register") { checkFlagsRegisterSyntax(field); return; }
    if (field_name_lower == "general_registers") { checkGeneralRegistersSyntax(field); return; }
}

void MachineDescriptionParser::checkWordSizeSyntax(const nlohmann::json& word_size_field) {
    uint16_t word_size;
    if (!word_size_field.is_number_unsigned()){
        success_parsing = false;
        std::cerr << "'word_size' must be an unsigned integer!" << std::endl;
        std::cout << word_size_field << std::endl;
    }else{
        word_size = word_size_field.get<uint16_t>();
        

        if (word_size < 8 || word_size > 256 ) { // checa se word_size e menor que 8 ou maior que 256
            success_parsing = false;
            std::cerr << "'word_size' must be at least 8 and less than 257!" << std::endl;
        }

        if (!(word_size > 0 && (word_size & (word_size - 1)) == 0)){ // checa se word_size nao e potencia de 2
            success_parsing = false;
            std::cerr << "'word_size' must be a power of 2!" << std::endl;
        } 
    }
}

void MachineDescriptionParser::checkRegisterAddressSizeSyntax(const nlohmann::json& register_address_size_field) {
    if (!register_address_size_field.is_number_unsigned()){
        success_parsing = false;
        std::cerr << "'register_address_size' must be an unsigned integer!" << std::endl;
    }else{
        auto register_address_size = register_address_size_field.get<uint8_t>();
    }

}

void MachineDescriptionParser::checkInstructionSizeSyntax(const nlohmann::json& instruction_size_field) {
    if (!instruction_size_field.is_number_unsigned()){
        success_parsing = false;
        std::cerr << "'instruction_size' must be an unsigned integer!" << std::endl;
    }else{
        auto instruction_size = instruction_size_field.get<uint8_t>();
    }
}

void MachineDescriptionParser::checkMemorySizeSyntax(const nlohmann::json& memory_size_field) {

    if (!memory_size_field.is_number_unsigned()){
        success_parsing = false;
        std::cerr << "'memory_size' must be an unsigned integer!" << std::endl;
    }else{
        auto memory_size = memory_size_field.get<uint64_t>();
    }
}

void MachineDescriptionParser::checkProgramCounterSyntax(const nlohmann::json& program_counter_field) {
    if (checkSubField(program_counter_field, "id")){
        if (!program_counter_field["id"].is_string()){
            success_parsing = false;
            std::cerr << "'program_counter.id' must be a string!" << std::endl;
        }else{
            auto program_counter_id = program_counter_field["id"].get<std::string>();
        }
    }else{
        std::cerr << "'program_counter.id' field is missing!" << std::endl;
    }

    if (checkSubField(program_counter_field, "size")) {
        if (!program_counter_field["size"].is_number_unsigned()){
            success_parsing = false;
            std::cerr << "'program_counter.size' must be an unsigned integer!" << std::endl;
        }else{
            auto program_counter_size = program_counter_field["size"].get<uint16_t>();
        }
    }else{
        std::cerr << "'program_counter.size' field is missing!" << std::endl;
    }

    if (!checkNumberOfExpectedSubFields(program_counter_field, 2)) {
        std::cerr << "Program counter has wrong number of subfields!" << std::endl;
        
    }
         
}

void MachineDescriptionParser::checkFlagsRegisterSyntax(const nlohmann::json& flags_register_field) {
    if (checkSubField(flags_register_field, "id")){
        if (!flags_register_field["id"].is_string()){
            success_parsing = false;
            std::cerr << "'flags_register.id' must be a string!" << std::endl;
        }else{
            auto program_counter_id = flags_register_field["id"].get<std::string>();
        }
    }else{
        std::cerr << "'flags_register.id' field is missing!" << std::endl;
    }

    if (checkSubField(flags_register_field, "size")) {
        if (!flags_register_field["size"].is_number_unsigned()){
            success_parsing = false;
            std::cerr << "'program_counter.size' must be an unsigned integer!" << std::endl;
        }else{
            auto program_counter_size = flags_register_field["size"].get<uint16_t>();
        }
    }else{
        std::cerr << "'flags_register.size' field is missing!" << std::endl;
    }

    if (!checkNumberOfExpectedSubFields(flags_register_field, 2)) {
        std::cout << "Flags register has wrong number of subfields!" << std::endl;
    }
        
}

void MachineDescriptionParser::checkGeneralRegistersSyntax(const nlohmann::json& general_registers_field) {
    if (checkSubField(general_registers_field, "size")) {
        if (!general_registers_field["size"].is_number_unsigned()){
            success_parsing = false;
            std::cerr << "'general_registers.size' must be an unsigned integer!" << std::endl;
        }else{
            auto general_registers_size = general_registers_field["size"].get<uint16_t>();
        }
    }else{
        std::cerr << "'general_registers.size' field is missing!" << std::endl;
    }


    if (checkSubField(general_registers_field, "number_of_registers")) {
        if (!general_registers_field["number_of_registers"].is_number_unsigned()){
            success_parsing = false;
            std::cerr << "'geberal_registers.number_of_registers' must be an unsigned integer!" << std::endl;
        }else{
            auto program_counter_size = general_registers_field["number_of_registers"].get<uint8_t>();
        }
    }else{
        std::cerr << "'flags_register.size' field is missing!" << std::endl;
    }

    if (checkSubField(general_registers_field, "id_pattern")) {
        if (!general_registers_field["id_pattern"].is_string()){
            success_parsing = false;
            std::cerr << "'general_registers.id_pattern' must be a string!" << std::endl;
        }else{
            auto program_counter_size = general_registers_field["id_pattern"].get<std::string>();
        }
    }else{
        std::cerr << "'general_registers.id_pattern' field is missing!" << std::endl;
    }


    if (!checkNumberOfExpectedSubFields(general_registers_field, 3)) {
        std::cout << "General registers has wrong number of subfields!" << std::endl;
    }
}

void MachineDescriptionParser::fillMachineDescriptionField(std::string field_name) {
    std::string field_name_lower = lowerFieldName(field_name);

    auto filler = field_fillers[field_name_lower]; // mapeia a funcao com o nome do campo

    if (filler == nullptr) {
        std::cerr << "Filler for field " << field_name_lower << " not found!" << std::endl;
        return;
    }else{
        filler(machine_description_json[field_name]); // chama a funcao para preencher o campo
    }
}

void MachineDescriptionParser::fillMachineDescription() {
    for (auto field:recognized_fields){
        fillMachineDescriptionField(field);
    }
}

void MachineDescriptionParser::parseMachineDescription() {
    if (!success_opening){ // checa se a abertura ou conversao foi bem sucedida
        return;
    }
    success_parsing = true;

    for (auto field = machine_description_json.begin(); field != machine_description_json.end(); field++) {
        checkFieldValidity(field.key());
    }
    
    checkRequiredFields();

    for (auto recognized_field:recognized_fields) {
        checkRequiredFieldSyntax(machine_description_json[recognized_field], recognized_field);
    }

    if (success_parsing){
        std::cout << "Machine description parsed successfully!" << std::endl;
        fillMachineDescription();
    }    
}