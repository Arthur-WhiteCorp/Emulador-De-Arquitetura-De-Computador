
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
      "root", "or", "xor", "and", "shift", "expr", "term", "factor", "primary"
    },
    std::vector<std::string>{
      "", "'='", "", "'R'", "'+'", "'-'", "'*'", "'/'", "'^'", "'<<'", "'>>'", 
      "'and'", "'or'", "'xor'"
    },
    std::vector<std::string>{
      "", "", "NUM", "REGISTER_PREFIX", "PLUS", "SUB", "MULT", "DIV", "EXP", 
      "SHIFT_LEFT", "SHIFT_RIGHT", "AND", "OR", "XOR", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,14,102,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,5,1,30,8,1,
  	10,1,12,1,33,9,1,1,2,1,2,1,2,1,2,1,2,1,2,5,2,41,8,2,10,2,12,2,44,9,2,
  	1,3,1,3,1,3,1,3,1,3,1,3,5,3,52,8,3,10,3,12,3,55,9,3,1,4,1,4,1,4,1,4,1,
  	4,1,4,5,4,63,8,4,10,4,12,4,66,9,4,1,5,1,5,1,5,1,5,1,5,1,5,5,5,74,8,5,
  	10,5,12,5,77,9,5,1,6,1,6,1,6,1,6,1,6,1,6,5,6,85,8,6,10,6,12,6,88,9,6,
  	1,7,1,7,1,7,1,7,1,7,3,7,95,8,7,1,8,1,8,1,8,3,8,100,8,8,1,8,0,6,2,4,6,
  	8,10,12,9,0,2,4,6,8,10,12,14,16,0,3,1,0,9,10,1,0,4,5,1,0,6,7,100,0,18,
  	1,0,0,0,2,23,1,0,0,0,4,34,1,0,0,0,6,45,1,0,0,0,8,56,1,0,0,0,10,67,1,0,
  	0,0,12,78,1,0,0,0,14,94,1,0,0,0,16,99,1,0,0,0,18,19,5,3,0,0,19,20,5,2,
  	0,0,20,21,5,1,0,0,21,22,3,2,1,0,22,1,1,0,0,0,23,24,6,1,-1,0,24,25,3,4,
  	2,0,25,31,1,0,0,0,26,27,10,1,0,0,27,28,5,12,0,0,28,30,3,4,2,0,29,26,1,
  	0,0,0,30,33,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,3,1,0,0,0,33,31,1,
  	0,0,0,34,35,6,2,-1,0,35,36,3,6,3,0,36,42,1,0,0,0,37,38,10,1,0,0,38,39,
  	5,13,0,0,39,41,3,6,3,0,40,37,1,0,0,0,41,44,1,0,0,0,42,40,1,0,0,0,42,43,
  	1,0,0,0,43,5,1,0,0,0,44,42,1,0,0,0,45,46,6,3,-1,0,46,47,3,8,4,0,47,53,
  	1,0,0,0,48,49,10,1,0,0,49,50,5,11,0,0,50,52,3,10,5,0,51,48,1,0,0,0,52,
  	55,1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,7,1,0,0,0,55,53,1,0,0,0,56,
  	57,6,4,-1,0,57,58,3,10,5,0,58,64,1,0,0,0,59,60,10,1,0,0,60,61,7,0,0,0,
  	61,63,3,10,5,0,62,59,1,0,0,0,63,66,1,0,0,0,64,62,1,0,0,0,64,65,1,0,0,
  	0,65,9,1,0,0,0,66,64,1,0,0,0,67,68,6,5,-1,0,68,69,3,12,6,0,69,75,1,0,
  	0,0,70,71,10,1,0,0,71,72,7,1,0,0,72,74,3,12,6,0,73,70,1,0,0,0,74,77,1,
  	0,0,0,75,73,1,0,0,0,75,76,1,0,0,0,76,11,1,0,0,0,77,75,1,0,0,0,78,79,6,
  	6,-1,0,79,80,3,14,7,0,80,86,1,0,0,0,81,82,10,1,0,0,82,83,7,2,0,0,83,85,
  	3,14,7,0,84,81,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,1,0,0,0,87,13,
  	1,0,0,0,88,86,1,0,0,0,89,95,3,16,8,0,90,91,3,16,8,0,91,92,5,8,0,0,92,
  	93,3,14,7,0,93,95,1,0,0,0,94,89,1,0,0,0,94,90,1,0,0,0,95,15,1,0,0,0,96,
  	97,5,3,0,0,97,100,5,2,0,0,98,100,5,2,0,0,99,96,1,0,0,0,99,98,1,0,0,0,
  	100,17,1,0,0,0,8,31,42,53,64,75,86,94,99
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

tree::TerminalNode* BehaviorParser::RootContext::REGISTER_PREFIX() {
  return getToken(BehaviorParser::REGISTER_PREFIX, 0);
}

tree::TerminalNode* BehaviorParser::RootContext::NUM() {
  return getToken(BehaviorParser::NUM, 0);
}

BehaviorParser::OrContext* BehaviorParser::RootContext::or_() {
  return getRuleContext<BehaviorParser::OrContext>(0);
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
    setState(18);
    match(BehaviorParser::REGISTER_PREFIX);
    setState(19);
    match(BehaviorParser::NUM);
    setState(20);
    match(BehaviorParser::T__0);
    setState(21);
    or_(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrContext ------------------------------------------------------------------

BehaviorParser::OrContext::OrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::XorContext* BehaviorParser::OrContext::xor_() {
  return getRuleContext<BehaviorParser::XorContext>(0);
}

BehaviorParser::OrContext* BehaviorParser::OrContext::or_() {
  return getRuleContext<BehaviorParser::OrContext>(0);
}

tree::TerminalNode* BehaviorParser::OrContext::OR() {
  return getToken(BehaviorParser::OR, 0);
}


size_t BehaviorParser::OrContext::getRuleIndex() const {
  return BehaviorParser::RuleOr;
}


std::any BehaviorParser::OrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitOr(this);
  else
    return visitor->visitChildren(this);
}


BehaviorParser::OrContext* BehaviorParser::or_() {
   return or_(0);
}

BehaviorParser::OrContext* BehaviorParser::or_(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BehaviorParser::OrContext *_localctx = _tracker.createInstance<OrContext>(_ctx, parentState);
  BehaviorParser::OrContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, BehaviorParser::RuleOr, precedence);

    

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
    setState(24);
    xor_(0);
    _ctx->stop = _input->LT(-1);
    setState(31);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<OrContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleOr);
        setState(26);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(27);
        match(BehaviorParser::OR);
        setState(28);
        xor_(0); 
      }
      setState(33);
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

//----------------- XorContext ------------------------------------------------------------------

BehaviorParser::XorContext::XorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::AndContext* BehaviorParser::XorContext::and_() {
  return getRuleContext<BehaviorParser::AndContext>(0);
}

BehaviorParser::XorContext* BehaviorParser::XorContext::xor_() {
  return getRuleContext<BehaviorParser::XorContext>(0);
}

tree::TerminalNode* BehaviorParser::XorContext::XOR() {
  return getToken(BehaviorParser::XOR, 0);
}


size_t BehaviorParser::XorContext::getRuleIndex() const {
  return BehaviorParser::RuleXor;
}


std::any BehaviorParser::XorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitXor(this);
  else
    return visitor->visitChildren(this);
}


BehaviorParser::XorContext* BehaviorParser::xor_() {
   return xor_(0);
}

BehaviorParser::XorContext* BehaviorParser::xor_(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BehaviorParser::XorContext *_localctx = _tracker.createInstance<XorContext>(_ctx, parentState);
  BehaviorParser::XorContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, BehaviorParser::RuleXor, precedence);

    

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
    setState(35);
    and_(0);
    _ctx->stop = _input->LT(-1);
    setState(42);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<XorContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleXor);
        setState(37);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(38);
        match(BehaviorParser::XOR);
        setState(39);
        and_(0); 
      }
      setState(44);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AndContext ------------------------------------------------------------------

BehaviorParser::AndContext::AndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::ShiftContext* BehaviorParser::AndContext::shift() {
  return getRuleContext<BehaviorParser::ShiftContext>(0);
}

BehaviorParser::AndContext* BehaviorParser::AndContext::and_() {
  return getRuleContext<BehaviorParser::AndContext>(0);
}

BehaviorParser::ExprContext* BehaviorParser::AndContext::expr() {
  return getRuleContext<BehaviorParser::ExprContext>(0);
}

tree::TerminalNode* BehaviorParser::AndContext::AND() {
  return getToken(BehaviorParser::AND, 0);
}


size_t BehaviorParser::AndContext::getRuleIndex() const {
  return BehaviorParser::RuleAnd;
}


std::any BehaviorParser::AndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAnd(this);
  else
    return visitor->visitChildren(this);
}


BehaviorParser::AndContext* BehaviorParser::and_() {
   return and_(0);
}

BehaviorParser::AndContext* BehaviorParser::and_(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BehaviorParser::AndContext *_localctx = _tracker.createInstance<AndContext>(_ctx, parentState);
  BehaviorParser::AndContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, BehaviorParser::RuleAnd, precedence);

    

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
    setState(46);
    shift(0);
    _ctx->stop = _input->LT(-1);
    setState(53);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AndContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAnd);
        setState(48);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(49);
        match(BehaviorParser::AND);
        setState(50);
        expr(0); 
      }
      setState(55);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ShiftContext ------------------------------------------------------------------

BehaviorParser::ShiftContext::ShiftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::ExprContext* BehaviorParser::ShiftContext::expr() {
  return getRuleContext<BehaviorParser::ExprContext>(0);
}

BehaviorParser::ShiftContext* BehaviorParser::ShiftContext::shift() {
  return getRuleContext<BehaviorParser::ShiftContext>(0);
}

tree::TerminalNode* BehaviorParser::ShiftContext::SHIFT_LEFT() {
  return getToken(BehaviorParser::SHIFT_LEFT, 0);
}

tree::TerminalNode* BehaviorParser::ShiftContext::SHIFT_RIGHT() {
  return getToken(BehaviorParser::SHIFT_RIGHT, 0);
}


size_t BehaviorParser::ShiftContext::getRuleIndex() const {
  return BehaviorParser::RuleShift;
}


std::any BehaviorParser::ShiftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitShift(this);
  else
    return visitor->visitChildren(this);
}


BehaviorParser::ShiftContext* BehaviorParser::shift() {
   return shift(0);
}

BehaviorParser::ShiftContext* BehaviorParser::shift(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BehaviorParser::ShiftContext *_localctx = _tracker.createInstance<ShiftContext>(_ctx, parentState);
  BehaviorParser::ShiftContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, BehaviorParser::RuleShift, precedence);

    size_t _la = 0;

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
    setState(57);
    expr(0);
    _ctx->stop = _input->LT(-1);
    setState(64);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ShiftContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleShift);
        setState(59);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(60);
        _la = _input->LA(1);
        if (!(_la == BehaviorParser::SHIFT_LEFT

        || _la == BehaviorParser::SHIFT_RIGHT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(61);
        expr(0); 
      }
      setState(66);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
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

BehaviorParser::TermContext* BehaviorParser::ExprContext::term() {
  return getRuleContext<BehaviorParser::TermContext>(0);
}

BehaviorParser::ExprContext* BehaviorParser::ExprContext::expr() {
  return getRuleContext<BehaviorParser::ExprContext>(0);
}

tree::TerminalNode* BehaviorParser::ExprContext::PLUS() {
  return getToken(BehaviorParser::PLUS, 0);
}

tree::TerminalNode* BehaviorParser::ExprContext::SUB() {
  return getToken(BehaviorParser::SUB, 0);
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
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, BehaviorParser::RuleExpr, precedence);

    size_t _la = 0;

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
    setState(68);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(75);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(70);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(71);
        _la = _input->LA(1);
        if (!(_la == BehaviorParser::PLUS

        || _la == BehaviorParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(72);
        term(0); 
      }
      setState(77);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

BehaviorParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::FactorContext* BehaviorParser::TermContext::factor() {
  return getRuleContext<BehaviorParser::FactorContext>(0);
}

BehaviorParser::TermContext* BehaviorParser::TermContext::term() {
  return getRuleContext<BehaviorParser::TermContext>(0);
}

tree::TerminalNode* BehaviorParser::TermContext::MULT() {
  return getToken(BehaviorParser::MULT, 0);
}

tree::TerminalNode* BehaviorParser::TermContext::DIV() {
  return getToken(BehaviorParser::DIV, 0);
}


size_t BehaviorParser::TermContext::getRuleIndex() const {
  return BehaviorParser::RuleTerm;
}


std::any BehaviorParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


BehaviorParser::TermContext* BehaviorParser::term() {
   return term(0);
}

BehaviorParser::TermContext* BehaviorParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BehaviorParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  BehaviorParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, BehaviorParser::RuleTerm, precedence);

    size_t _la = 0;

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
    setState(79);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(86);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(81);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(82);
        _la = _input->LA(1);
        if (!(_la == BehaviorParser::MULT

        || _la == BehaviorParser::DIV)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(83);
        factor(); 
      }
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

BehaviorParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::PrimaryContext* BehaviorParser::FactorContext::primary() {
  return getRuleContext<BehaviorParser::PrimaryContext>(0);
}

BehaviorParser::FactorContext* BehaviorParser::FactorContext::factor() {
  return getRuleContext<BehaviorParser::FactorContext>(0);
}

tree::TerminalNode* BehaviorParser::FactorContext::EXP() {
  return getToken(BehaviorParser::EXP, 0);
}


size_t BehaviorParser::FactorContext::getRuleIndex() const {
  return BehaviorParser::RuleFactor;
}


std::any BehaviorParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::FactorContext* BehaviorParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 14, BehaviorParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(89);
      primary();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(90);
      primary();

      setState(91);
      match(BehaviorParser::EXP);
      setState(92);
      factor();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

BehaviorParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::PrimaryContext::REGISTER_PREFIX() {
  return getToken(BehaviorParser::REGISTER_PREFIX, 0);
}

tree::TerminalNode* BehaviorParser::PrimaryContext::NUM() {
  return getToken(BehaviorParser::NUM, 0);
}


size_t BehaviorParser::PrimaryContext::getRuleIndex() const {
  return BehaviorParser::RulePrimary;
}


std::any BehaviorParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::PrimaryContext* BehaviorParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 16, BehaviorParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(99);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::REGISTER_PREFIX: {
        enterOuterAlt(_localctx, 1);
        setState(96);
        match(BehaviorParser::REGISTER_PREFIX);
        setState(97);
        match(BehaviorParser::NUM);
        break;
      }

      case BehaviorParser::NUM: {
        enterOuterAlt(_localctx, 2);
        setState(98);
        match(BehaviorParser::NUM);
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
    case 1: return orSempred(antlrcpp::downCast<OrContext *>(context), predicateIndex);
    case 2: return xorSempred(antlrcpp::downCast<XorContext *>(context), predicateIndex);
    case 3: return andSempred(antlrcpp::downCast<AndContext *>(context), predicateIndex);
    case 4: return shiftSempred(antlrcpp::downCast<ShiftContext *>(context), predicateIndex);
    case 5: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);
    case 6: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool BehaviorParser::orSempred(OrContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool BehaviorParser::xorSempred(XorContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool BehaviorParser::andSempred(AndContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool BehaviorParser::shiftSempred(ShiftContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool BehaviorParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool BehaviorParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

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
