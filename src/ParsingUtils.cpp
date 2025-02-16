#include <ParsingUtils.hpp>
#include <iostream>



ParsingUtils::ParsingUtils() {
    initializeErrorFlags();
   
}

ParsingUtils::~ParsingUtils() {
    if (!close_called) {
        closeFile();
    }
}

void ParsingUtils::initializeErrorFlags() {
    success_opening = true;
    success_converting = true;
}
void ParsingUtils::openFile(std::string file_path) {
    this->file_path = file_path;
    file.open(file_path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        success_opening = false;
        return;
    }
    success_opening = true;
    return;
}

void ParsingUtils::turnFileToJson() {
    try {
        json = nlohmann::json::parse(file);
        std::cout << "Conversion to JSON was successful!" << std::endl;
        success_converting = true;
        return;
    } catch (const nlohmann::json::parse_error& e) {
        std::cerr << "Failed to convert file to JSON: " << e.what() << std::endl;
        success_converting = false;
        return;
    }
}

void ParsingUtils::closeFile() {

    if (!success_opening){ // checa se a abertura foi bem sucedida
        return;
    }
    
    close_called = true;

    file.close();
    
    if (file.is_open()) {
        std::cerr << "Failed to close the file: " << file_path << std::endl;
        success_closing = false;
        return;  
    } else {
        std::cout << "Successfully closed the file: " << file_path << std::endl;
        success_closing = true;
        return;
    }

}
