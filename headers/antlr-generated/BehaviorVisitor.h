
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

    virtual std::any visitExpr(BehaviorParser::ExprContext *context) = 0;

    virtual std::any visitEXPONENTIATION(BehaviorParser::EXPONENTIATIONContext *context) = 0;

    virtual std::any visitMULTIPLICATION(BehaviorParser::MULTIPLICATIONContext *context) = 0;

    virtual std::any visitDIVISION(BehaviorParser::DIVISIONContext *context) = 0;

    virtual std::any visitADDITION(BehaviorParser::ADDITIONContext *context) = 0;

    virtual std::any visitSUBTRACTION(BehaviorParser::SUBTRACTIONContext *context) = 0;

    virtual std::any visitSHL(BehaviorParser::SHLContext *context) = 0;

    virtual std::any visitSHR(BehaviorParser::SHRContext *context) = 0;

    virtual std::any visitAND_BIT_WISE(BehaviorParser::AND_BIT_WISEContext *context) = 0;

    virtual std::any visitXOR_BIT_WISE(BehaviorParser::XOR_BIT_WISEContext *context) = 0;

    virtual std::any visitOR_BIT_WISE(BehaviorParser::OR_BIT_WISEContext *context) = 0;


};

