#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <Machine.hpp>

int main() {
    std::ifstream f("../testes/example.json");
     if (!f.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }
    nlohmann::json data = nlohmann::json::parse(f);
    std::cout << data["name"] << std::endl;
    return 0;
}
