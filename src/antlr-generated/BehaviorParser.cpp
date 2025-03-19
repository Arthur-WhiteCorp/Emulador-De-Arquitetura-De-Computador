
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
      "root", "expr"
    },
    std::vector<std::string>{
      "", "", "'+'", "'-'", "'*'", "'another one'", "'asdsd'"
    },
    std::vector<std::string>{
      "", "NUM", "PLUS", "SUB", "TEST", "SUP", "TL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,7,18,2,0,7,0,2,1,7,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,5,1,13,8,1,10,
  	1,12,1,16,9,1,1,1,0,1,2,2,0,2,0,1,1,0,2,3,16,0,4,1,0,0,0,2,6,1,0,0,0,
  	4,5,3,2,1,0,5,1,1,0,0,0,6,7,6,1,-1,0,7,8,5,1,0,0,8,14,1,0,0,0,9,10,10,
  	2,0,0,10,11,7,0,0,0,11,13,3,2,1,3,12,9,1,0,0,0,13,16,1,0,0,0,14,12,1,
  	0,0,0,14,15,1,0,0,0,15,3,1,0,0,0,16,14,1,0,0,0,1,14
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
    setState(4);
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
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, BehaviorParser::RuleExpr, precedence);

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
    setState(7);
    match(BehaviorParser::NUM);
    _ctx->stop = _input->LT(-1);
    setState(14);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr);
        setState(9);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(10);
        _la = _input->LA(1);
        if (!(_la == BehaviorParser::PLUS

        || _la == BehaviorParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(11);
        expr(3); 
      }
      setState(16);
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
