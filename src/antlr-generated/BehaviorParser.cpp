
// Generated from grammars/Behavior.g4 by ANTLR 4.13.2


#include "BehaviorVisitor.h"

#include "BehaviorParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct BehaviorParserStaticData final {
  BehaviorParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BehaviorParserStaticData(const BehaviorParserStaticData&) = delete;
  BehaviorParserStaticData(BehaviorParserStaticData&&) = delete;
  BehaviorParserStaticData& operator=(const BehaviorParserStaticData&) = delete;
  BehaviorParserStaticData& operator=(BehaviorParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag behaviorParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<BehaviorParserStaticData> behaviorParserStaticData = nullptr;

void behaviorParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (behaviorParserStaticData != nullptr) {
    return;
  }
#else
  assert(behaviorParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<BehaviorParserStaticData>(
    std::vector<std::string>{
      "root", "expr", "binary_op"
    },
    std::vector<std::string>{
      "", "", "'R'", "'+'", "'-'", "'*'", "'/'", "'^'", "'<<'", "'>>'", 
      "'and'", "'or'", "'xor'"
    },
    std::vector<std::string>{
      "", "NUM", "REGISTER_PREFIX", "PLUS", "SUB", "MULT", "DIV", "EXP", 
      "SHIFT_LEFT", "SHIFT_RIGHT", "AND", "OR", "XOR", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,13,33,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	5,1,16,8,1,10,1,12,1,19,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,
  	2,31,8,2,1,2,0,1,2,3,0,2,4,0,0,39,0,6,1,0,0,0,2,8,1,0,0,0,4,30,1,0,0,
  	0,6,7,3,2,1,0,7,1,1,0,0,0,8,9,6,1,-1,0,9,10,5,1,0,0,10,17,1,0,0,0,11,
  	12,10,2,0,0,12,13,3,4,2,0,13,14,3,2,1,3,14,16,1,0,0,0,15,11,1,0,0,0,16,
  	19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,3,1,0,0,0,19,17,1,0,0,0,20,
  	31,5,7,0,0,21,31,5,5,0,0,22,31,5,6,0,0,23,31,5,3,0,0,24,31,5,4,0,0,25,
  	31,5,8,0,0,26,31,5,9,0,0,27,31,5,10,0,0,28,31,5,12,0,0,29,31,5,11,0,0,
  	30,20,1,0,0,0,30,21,1,0,0,0,30,22,1,0,0,0,30,23,1,0,0,0,30,24,1,0,0,0,
  	30,25,1,0,0,0,30,26,1,0,0,0,30,27,1,0,0,0,30,28,1,0,0,0,30,29,1,0,0,0,
  	31,5,1,0,0,0,2,17,30
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  behaviorParserStaticData = std::move(staticData);
}

}

BehaviorParser::BehaviorParser(TokenStream *input) : BehaviorParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

BehaviorParser::BehaviorParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  BehaviorParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *behaviorParserStaticData->atn, behaviorParserStaticData->decisionToDFA, behaviorParserStaticData->sharedContextCache, options);
}

BehaviorParser::~BehaviorParser() {
  delete _interpreter;
}

const atn::ATN& BehaviorParser::getATN() const {
  return *behaviorParserStaticData->atn;
}

std::string BehaviorParser::getGrammarFileName() const {
  return "Behavior.g4";
}

const std::vector<std::string>& BehaviorParser::getRuleNames() const {
  return behaviorParserStaticData->ruleNames;
}

const dfa::Vocabulary& BehaviorParser::getVocabulary() const {
  return behaviorParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView BehaviorParser::getSerializedATN() const {
  return behaviorParserStaticData->serializedATN;
}


//----------------- RootContext ------------------------------------------------------------------

BehaviorParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::ExprContext* BehaviorParser::RootContext::expr() {
  return getRuleContext<BehaviorParser::ExprContext>(0);
}


size_t BehaviorParser::RootContext::getRuleIndex() const {
  return BehaviorParser::RuleRoot;
}


std::any BehaviorParser::RootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitRoot(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::RootContext* BehaviorParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, BehaviorParser::RuleRoot);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(6);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

BehaviorParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::ExprContext::NUM() {
  return getToken(BehaviorParser::NUM, 0);
}

std::vector<BehaviorParser::ExprContext *> BehaviorParser::ExprContext::expr() {
  return getRuleContexts<BehaviorParser::ExprContext>();
}

BehaviorParser::ExprContext* BehaviorParser::ExprContext::expr(size_t i) {
  return getRuleContext<BehaviorParser::ExprContext>(i);
}

BehaviorParser::Binary_opContext* BehaviorParser::ExprContext::binary_op() {
  return getRuleContext<BehaviorParser::Binary_opContext>(0);
}


size_t BehaviorParser::ExprContext::getRuleIndex() const {
  return BehaviorParser::RuleExpr;
}


std::any BehaviorParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


BehaviorParser::ExprContext* BehaviorParser::expr() {
   return expr(0);
}

BehaviorParser::ExprContext* BehaviorParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BehaviorParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  BehaviorParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, BehaviorParser::RuleExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(9);
    match(BehaviorParser::NUM);
    _ctx->stop = _input->LT(-1);
    setState(17);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(11);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");

        setState(12);
        binary_op();
        setState(13);
        expr(3); 
      }
      setState(19);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Binary_opContext ------------------------------------------------------------------

BehaviorParser::Binary_opContext::Binary_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorParser::Binary_opContext::getRuleIndex() const {
  return BehaviorParser::RuleBinary_op;
}

void BehaviorParser::Binary_opContext::copyFrom(Binary_opContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AND_BIT_WISEContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::AND_BIT_WISEContext::AND() {
  return getToken(BehaviorParser::AND, 0);
}

BehaviorParser::AND_BIT_WISEContext::AND_BIT_WISEContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::AND_BIT_WISEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAND_BIT_WISE(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MULTIPLICATIONContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::MULTIPLICATIONContext::MULT() {
  return getToken(BehaviorParser::MULT, 0);
}

BehaviorParser::MULTIPLICATIONContext::MULTIPLICATIONContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::MULTIPLICATIONContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitMULTIPLICATION(this);
  else
    return visitor->visitChildren(this);
}
//----------------- XOR_BIT_WISEContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::XOR_BIT_WISEContext::XOR() {
  return getToken(BehaviorParser::XOR, 0);
}

BehaviorParser::XOR_BIT_WISEContext::XOR_BIT_WISEContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::XOR_BIT_WISEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitXOR_BIT_WISE(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EXPONENTIATIONContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::EXPONENTIATIONContext::EXP() {
  return getToken(BehaviorParser::EXP, 0);
}

BehaviorParser::EXPONENTIATIONContext::EXPONENTIATIONContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::EXPONENTIATIONContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEXPONENTIATION(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ADDITIONContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::ADDITIONContext::PLUS() {
  return getToken(BehaviorParser::PLUS, 0);
}

BehaviorParser::ADDITIONContext::ADDITIONContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::ADDITIONContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitADDITION(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SUBTRACTIONContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::SUBTRACTIONContext::SUB() {
  return getToken(BehaviorParser::SUB, 0);
}

BehaviorParser::SUBTRACTIONContext::SUBTRACTIONContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::SUBTRACTIONContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSUBTRACTION(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SHLContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::SHLContext::SHIFT_LEFT() {
  return getToken(BehaviorParser::SHIFT_LEFT, 0);
}

BehaviorParser::SHLContext::SHLContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::SHLContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSHL(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SHRContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::SHRContext::SHIFT_RIGHT() {
  return getToken(BehaviorParser::SHIFT_RIGHT, 0);
}

BehaviorParser::SHRContext::SHRContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::SHRContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSHR(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DIVISIONContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::DIVISIONContext::DIV() {
  return getToken(BehaviorParser::DIV, 0);
}

BehaviorParser::DIVISIONContext::DIVISIONContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::DIVISIONContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDIVISION(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OR_BIT_WISEContext ------------------------------------------------------------------

tree::TerminalNode* BehaviorParser::OR_BIT_WISEContext::OR() {
  return getToken(BehaviorParser::OR, 0);
}

BehaviorParser::OR_BIT_WISEContext::OR_BIT_WISEContext(Binary_opContext *ctx) { copyFrom(ctx); }


std::any BehaviorParser::OR_BIT_WISEContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitOR_BIT_WISE(this);
  else
    return visitor->visitChildren(this);
}
BehaviorParser::Binary_opContext* BehaviorParser::binary_op() {
  Binary_opContext *_localctx = _tracker.createInstance<Binary_opContext>(_ctx, getState());
  enterRule(_localctx, 4, BehaviorParser::RuleBinary_op);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(30);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::EXP: {
        _localctx = _tracker.createInstance<BehaviorParser::EXPONENTIATIONContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(20);
        match(BehaviorParser::EXP);
        break;
      }

      case BehaviorParser::MULT: {
        _localctx = _tracker.createInstance<BehaviorParser::MULTIPLICATIONContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(21);
        match(BehaviorParser::MULT);
        break;
      }

      case BehaviorParser::DIV: {
        _localctx = _tracker.createInstance<BehaviorParser::DIVISIONContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(22);
        match(BehaviorParser::DIV);
        break;
      }

      case BehaviorParser::PLUS: {
        _localctx = _tracker.createInstance<BehaviorParser::ADDITIONContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(23);
        match(BehaviorParser::PLUS);
        break;
      }

      case BehaviorParser::SUB: {
        _localctx = _tracker.createInstance<BehaviorParser::SUBTRACTIONContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(24);
        match(BehaviorParser::SUB);
        break;
      }

      case BehaviorParser::SHIFT_LEFT: {
        _localctx = _tracker.createInstance<BehaviorParser::SHLContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(25);
        match(BehaviorParser::SHIFT_LEFT);
        break;
      }

      case BehaviorParser::SHIFT_RIGHT: {
        _localctx = _tracker.createInstance<BehaviorParser::SHRContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(26);
        match(BehaviorParser::SHIFT_RIGHT);
        break;
      }

      case BehaviorParser::AND: {
        _localctx = _tracker.createInstance<BehaviorParser::AND_BIT_WISEContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(27);
        match(BehaviorParser::AND);
        break;
      }

      case BehaviorParser::XOR: {
        _localctx = _tracker.createInstance<BehaviorParser::XOR_BIT_WISEContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(28);
        match(BehaviorParser::XOR);
        break;
      }

      case BehaviorParser::OR: {
        _localctx = _tracker.createInstance<BehaviorParser::OR_BIT_WISEContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(29);
        match(BehaviorParser::OR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool BehaviorParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool BehaviorParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void BehaviorParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  behaviorParserInitialize();
#else
  ::antlr4::internal::call_once(behaviorParserOnceFlag, behaviorParserInitialize);
#endif
}
