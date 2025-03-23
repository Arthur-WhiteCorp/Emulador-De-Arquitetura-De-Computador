
// Generated from grammars/Behavior.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by BehaviorParser.
 */
class  BehaviorVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by BehaviorParser.
   */
    virtual std::any visitRoot(BehaviorParser::RootContext *context) = 0;

    virtual std::any visitOr(BehaviorParser::OrContext *context) = 0;

    virtual std::any visitXor(BehaviorParser::XorContext *context) = 0;

    virtual std::any visitAnd(BehaviorParser::AndContext *context) = 0;

    virtual std::any visitShift(BehaviorParser::ShiftContext *context) = 0;

    virtual std::any visitExpr(BehaviorParser::ExprContext *context) = 0;

    virtual std::any visitTerm(BehaviorParser::TermContext *context) = 0;

    virtual std::any visitFactor(BehaviorParser::FactorContext *context) = 0;

    virtual std::any visitPrimary(BehaviorParser::PrimaryContext *context) = 0;

    virtual std::any visitParentheses(BehaviorParser::ParenthesesContext *context) = 0;


};

