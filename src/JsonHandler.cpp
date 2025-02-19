#include <JsonHandler.hpp>
#include <iostream>



JsonHandler::JsonHandler(std::string file_path) {
    initializeErrorFlags();
    openFile(file_path);
    turnFileToJson();
}

JsonHandler::~JsonHandler() {
    if (!close_called) {
        closeFile();
    }
}

nlohmann::json JsonHandler::getJson() {
    return json;
}


void JsonHandler::initializeErrorFlags() {
    success_opening = true;
    success_converting = true;
}
void JsonHandler::openFile(std::string file_path) {
    this->file_path = file_path;
    file.open(file_path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        success_opening = false;
        return;
    }else {
        std::cout << "Successfully opened file!" << std::endl;
    }
    success_opening = true;
    return;
}

void JsonHandler::turnFileToJson() {
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

void JsonHandler::closeFile() {

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

bool JsonHandler::isValidJson() {
    return success_converting && success_opening;
}
