
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


};

