#include <antlr4-runtime.h>


class BehaviorErrorListener : public antlr4::BaseErrorListener {
private:
        std::string instruction_name;
        std::string instruction_behavior;
        const antlr4::CommonTokenStream& tokens;
        

public:
        BehaviorErrorListener(std::string instruction_name, std::string instruction_behavior, antlr4::CommonTokenStream& tokens): instruction_name(instruction_name), instruction_behavior(instruction_behavior), tokens(tokens) {};

        virtual void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t column, const std::string &msg, std::exception_ptr e) override;
        std::string getMessage() const;
        std::string getFile() const;
        int getLine() const;
        int getColumn() const;
};


