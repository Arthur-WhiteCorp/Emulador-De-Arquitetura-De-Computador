
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


};

