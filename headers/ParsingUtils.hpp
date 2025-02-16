#ifndef PARSING_UTILS_HPP
#define PARSING_UTILS_HPP
#include <nlohmann/json.hpp>
#include <fstream>

class ParsingUtils {
public:

    ParsingUtils();
    ~ParsingUtils();
    const nlohmann::json& getJson();
    bool isValidJson();
private:

    std::string file_path; // Caminho do arquivo
    std::ifstream file; // Arquivo de descricao
    nlohmann::json json; // JSON de descricao
     
    bool success_opening; // true se abriu
    bool success_converting;  // true se convertiu para json
    bool success_closing; // true se fechou
    bool close_called; // true se chamou closeFile()

    void initializeErrorFlags(); // inicializa as flags de erro
    void openFile(std::string file_path); // Abre o arquivo de descricao da maquina
    void turnFileToJson(); // Transforma o arquivo de descricao da maquina em um JSON
    void closeFile(); // Fecha o arquivo de descricao da maquina

};



#endif

