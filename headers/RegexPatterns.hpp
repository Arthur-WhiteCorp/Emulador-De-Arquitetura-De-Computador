#ifndef REGEX_PATTERNS_HPP 
#define REGEX_PATTERNS_HPP

#include <string>
#include <unordered_map>

namespace RegexPatterns {

    enum class PatternType {
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
    static const std::string binary_operator = R"((\+|\-|\*|\/|^|<<|>>|and|or|xor|not))";
    static const std::string conditional_operator = R"((==|!=|<=|>=|<|>))";
    static const std::string flags_register_pos = "(flags_register)(\\[" + unsigned_num + "\\])";

    static const std::unordered_map<PatternType, std::string> regex_patterns = {
        {PatternType::INSTRUCTION_NAME, instruction_name},
        {PatternType::FLAGS_REGISTER_POS, flags_register_pos},
        {PatternType::REGISTER_ID, register_id },
        {PatternType::REGISTER_ID_OR_NUMBER, register_id_or_number},
        {PatternType::UNSIGNED_NUM, unsigned_num},
        {PatternType::NUMBER, number},
        {PatternType::BINARY_OPERATOR, binary_operator},
        {PatternType::CONDITIONAL_OPERATOR, conditional_operator},
        {PatternType::NEGATION, negation}
    };
}





#endif
