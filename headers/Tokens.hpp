#ifndef TOKENS_HPP
#define TOKENS_HPP
#include <regex>
#include <string>
#include <unordered_map>

namespace Tokens {

    enum class TokenType {
        INSTRUCTION_NAME,
        REGISTER_ID,
        UNSIGNED_NUM,
        NUMBER,
        REGISTER_ID_OR_NUMBER,
        OPERATOR,
        FLAGS_REGISTER_POS,
        CONDITIONAL_OPERATOR
    };

    static const std::string instruction_name = R"((\w+))";
    static const std::string register_id = R"((\w+))";
    static const std::string unsigned_num = R"((\d+))";
    static const std::string number = R"((-?\d+))";
    static const std::string register_id_or_number = "(" + register_id + "|" + number + ")";
    static const std::string my_operator = R"((\+|\-|\*|\/|^|<<|>>|and|not|or))";
    static const std::string conditional_operator = R"((==|!=|<=|>=|<|>|!))";
    static const std::string flags_register_pos = "(flags_register)(\\[" + unsigned_num + "\\])";

    static const std::unordered_map<TokenType, std::string> token_patterns = {
        {TokenType::INSTRUCTION_NAME, instruction_name},
        {TokenType::FLAGS_REGISTER_POS, flags_register_pos},
        {TokenType::INSTRUCTION_NAME, instruction_name},
        {TokenType::REGISTER_ID, register_id },
        {TokenType::UNSIGNED_NUM, unsigned_num},
        {TokenType::NUMBER, number},
        {TokenType::OPERATOR, my_operator},
        {TokenType::CONDITIONAL_OPERATOR, conditional_operator}
    };
}





#endif
