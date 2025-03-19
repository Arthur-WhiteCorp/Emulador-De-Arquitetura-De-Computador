
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
      "NUM", "REGISTER", "PLUS", "SUB", "TEST", "SUP", "TL", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "'R[0-9]+'", "'+'", "'-'", "'*'", "'another one'", "'asdsd'"
    },
    std::vector<std::string>{
      "", "NUM", "REGISTER", "PLUS", "SUB", "TEST", "SUP", "TL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,8,61,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,1,0,4,0,19,8,0,11,0,12,0,20,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,7,4,7,56,8,7,11,7,12,7,57,1,7,1,7,0,0,8,1,1,
  	3,2,5,3,7,4,9,5,11,6,13,7,15,8,1,0,2,1,0,48,57,2,0,10,10,32,32,62,0,1,
  	1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,
  	0,13,1,0,0,0,0,15,1,0,0,0,1,18,1,0,0,0,3,22,1,0,0,0,5,30,1,0,0,0,7,32,
  	1,0,0,0,9,34,1,0,0,0,11,36,1,0,0,0,13,48,1,0,0,0,15,55,1,0,0,0,17,19,
  	7,0,0,0,18,17,1,0,0,0,19,20,1,0,0,0,20,18,1,0,0,0,20,21,1,0,0,0,21,2,
  	1,0,0,0,22,23,5,82,0,0,23,24,5,91,0,0,24,25,5,48,0,0,25,26,5,45,0,0,26,
  	27,5,57,0,0,27,28,5,93,0,0,28,29,5,43,0,0,29,4,1,0,0,0,30,31,5,43,0,0,
  	31,6,1,0,0,0,32,33,5,45,0,0,33,8,1,0,0,0,34,35,5,42,0,0,35,10,1,0,0,0,
  	36,37,5,97,0,0,37,38,5,110,0,0,38,39,5,111,0,0,39,40,5,116,0,0,40,41,
  	5,104,0,0,41,42,5,101,0,0,42,43,5,114,0,0,43,44,5,32,0,0,44,45,5,111,
  	0,0,45,46,5,110,0,0,46,47,5,101,0,0,47,12,1,0,0,0,48,49,5,97,0,0,49,50,
  	5,115,0,0,50,51,5,100,0,0,51,52,5,115,0,0,52,53,5,100,0,0,53,14,1,0,0,
  	0,54,56,7,1,0,0,55,54,1,0,0,0,56,57,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,
  	0,58,59,1,0,0,0,59,60,6,7,0,0,60,16,1,0,0,0,3,0,20,57,1,6,0,0
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
