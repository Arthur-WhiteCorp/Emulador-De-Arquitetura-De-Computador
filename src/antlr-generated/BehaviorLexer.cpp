
// Generated from grammars/Behavior.g4 by ANTLR 4.13.2


#include "BehaviorLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct BehaviorLexerStaticData final {
  BehaviorLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BehaviorLexerStaticData(const BehaviorLexerStaticData&) = delete;
  BehaviorLexerStaticData(BehaviorLexerStaticData&&) = delete;
  BehaviorLexerStaticData& operator=(const BehaviorLexerStaticData&) = delete;
  BehaviorLexerStaticData& operator=(BehaviorLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag behaviorlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<BehaviorLexerStaticData> behaviorlexerLexerStaticData = nullptr;

void behaviorlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (behaviorlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(behaviorlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<BehaviorLexerStaticData>(
    std::vector<std::string>{
      "NUM", "PLUS", "SUB", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "'+'", "'-'"
    },
    std::vector<std::string>{
      "", "NUM", "PLUS", "SUB", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,4,25,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,4,0,11,8,0,11,0,12,
  	0,12,1,1,1,1,1,2,1,2,1,3,4,3,20,8,3,11,3,12,3,21,1,3,1,3,0,0,4,1,1,3,
  	2,5,3,7,4,1,0,2,1,0,48,57,2,0,10,10,32,32,26,0,1,1,0,0,0,0,3,1,0,0,0,
  	0,5,1,0,0,0,0,7,1,0,0,0,1,10,1,0,0,0,3,14,1,0,0,0,5,16,1,0,0,0,7,19,1,
  	0,0,0,9,11,7,0,0,0,10,9,1,0,0,0,11,12,1,0,0,0,12,10,1,0,0,0,12,13,1,0,
  	0,0,13,2,1,0,0,0,14,15,5,43,0,0,15,4,1,0,0,0,16,17,5,45,0,0,17,6,1,0,
  	0,0,18,20,7,1,0,0,19,18,1,0,0,0,20,21,1,0,0,0,21,19,1,0,0,0,21,22,1,0,
  	0,0,22,23,1,0,0,0,23,24,6,3,0,0,24,8,1,0,0,0,3,0,12,21,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  behaviorlexerLexerStaticData = std::move(staticData);
}

}

BehaviorLexer::BehaviorLexer(CharStream *input) : Lexer(input) {
  BehaviorLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *behaviorlexerLexerStaticData->atn, behaviorlexerLexerStaticData->decisionToDFA, behaviorlexerLexerStaticData->sharedContextCache);
}

BehaviorLexer::~BehaviorLexer() {
  delete _interpreter;
}

std::string BehaviorLexer::getGrammarFileName() const {
  return "Behavior.g4";
}

const std::vector<std::string>& BehaviorLexer::getRuleNames() const {
  return behaviorlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& BehaviorLexer::getChannelNames() const {
  return behaviorlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& BehaviorLexer::getModeNames() const {
  return behaviorlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& BehaviorLexer::getVocabulary() const {
  return behaviorlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView BehaviorLexer::getSerializedATN() const {
  return behaviorlexerLexerStaticData->serializedATN;
}

const atn::ATN& BehaviorLexer::getATN() const {
  return *behaviorlexerLexerStaticData->atn;
}




void BehaviorLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  behaviorlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(behaviorlexerLexerOnceFlag, behaviorlexerLexerInitialize);
#endif
}
