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
        BINARY_OPERATOR,
        FLAGS_REGISTER_POS,
        CONDITIONAL_OPERATOR,
        NEGATION
    };

    static const std::string instruction_name = R"((\w+))";
    static const std::string register_id = R"((\w+))";
    static const std::string unsigned_num = R"((\d+))";
    static const std::string number = R"((-?\d+))";
    static const std::string register_id_or_number = "(" + register_id + "|" + number + ")";
    static const std::string negation = R"((not))";
    static const std::string binary_operator = R"((\+|\-|\*|\/|^|<<|>>|and|or|xor))";
    static const std::string conditional_operator = R"((==|!=|<=|>=|<|>|!))";
    static const std::string flags_register_pos = "(flags_register)(\\[" + unsigned_num + "\\])";

    static const std::unordered_map<TokenType, std::string> token_patterns = {
        {TokenType::INSTRUCTION_NAME, instruction_name},
        {TokenType::FLAGS_REGISTER_POS, flags_register_pos},
        {TokenType::REGISTER_ID, register_id },
        {TokenType::REGISTER_ID_OR_NUMBER, register_id_or_number},
        {TokenType::UNSIGNED_NUM, unsigned_num},
        {TokenType::NUMBER, number},
        {TokenType::BINARY_OPERATOR, binary_operator},
        {TokenType::CONDITIONAL_OPERATOR, conditional_operator},
        {TokenType::NEGATION, negation}
    };
}





#endif
