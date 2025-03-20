
// Generated from grammars/Behavior.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorVisitor.h"


/**
 * This class provides an empty implementation of BehaviorVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  BehaviorBaseVisitor : public BehaviorVisitor {
public:

  virtual std::any visitRoot(BehaviorParser::RootContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(BehaviorParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEXPONENTIATION(BehaviorParser::EXPONENTIATIONContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMULTIPLICATION(BehaviorParser::MULTIPLICATIONContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDIVISION(BehaviorParser::DIVISIONContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitADDITION(BehaviorParser::ADDITIONContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSUBTRACTION(BehaviorParser::SUBTRACTIONContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSHL(BehaviorParser::SHLContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSHR(BehaviorParser::SHRContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAND_BIT_WISE(BehaviorParser::AND_BIT_WISEContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXOR_BIT_WISE(BehaviorParser::XOR_BIT_WISEContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOR_BIT_WISE(BehaviorParser::OR_BIT_WISEContext *ctx) override {
    return visitChildren(ctx);
  }


};

