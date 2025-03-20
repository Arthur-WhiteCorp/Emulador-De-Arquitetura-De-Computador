
// Generated from grammars/Behavior.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  BehaviorParser : public antlr4::Parser {
public:
  enum {
    NUM = 1, REGISTER_PREFIX = 2, PLUS = 3, SUB = 4, MULT = 5, DIV = 6, 
    EXP = 7, SHIFT_LEFT = 8, SHIFT_RIGHT = 9, AND = 10, OR = 11, XOR = 12, 
    WS = 13
  };

  enum {
    RuleRoot = 0, RuleExpr = 1, RuleBinary_op = 2
  };

  explicit BehaviorParser(antlr4::TokenStream *input);

  BehaviorParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~BehaviorParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class RootContext;
  class ExprContext;
  class Binary_opContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootContext* root();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    Binary_opContext *binary_op();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  Binary_opContext : public antlr4::ParserRuleContext {
  public:
    Binary_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Binary_opContext() = default;
    void copyFrom(Binary_opContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AND_BIT_WISEContext : public Binary_opContext {
  public:
    AND_BIT_WISEContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *AND();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MULTIPLICATIONContext : public Binary_opContext {
  public:
    MULTIPLICATIONContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *MULT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  XOR_BIT_WISEContext : public Binary_opContext {
  public:
    XOR_BIT_WISEContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *XOR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EXPONENTIATIONContext : public Binary_opContext {
  public:
    EXPONENTIATIONContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *EXP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ADDITIONContext : public Binary_opContext {
  public:
    ADDITIONContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *PLUS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SUBTRACTIONContext : public Binary_opContext {
  public:
    SUBTRACTIONContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *SUB();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SHLContext : public Binary_opContext {
  public:
    SHLContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *SHIFT_LEFT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SHRContext : public Binary_opContext {
  public:
    SHRContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *SHIFT_RIGHT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DIVISIONContext : public Binary_opContext {
  public:
    DIVISIONContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *DIV();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OR_BIT_WISEContext : public Binary_opContext {
  public:
    OR_BIT_WISEContext(Binary_opContext *ctx);

    antlr4::tree::TerminalNode *OR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Binary_opContext* binary_op();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

