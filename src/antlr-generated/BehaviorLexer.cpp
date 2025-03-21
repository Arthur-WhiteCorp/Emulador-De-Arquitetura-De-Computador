
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
      "T__0", "NUM", "REGISTER_PREFIX", "PLUS", "SUB", "MULT", "DIV", "EXP", 
      "SHIFT_LEFT", "SHIFT_RIGHT", "AND", "OR", "XOR", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,14,72,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,
  	1,0,1,1,4,1,33,8,1,11,1,12,1,34,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,
  	6,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,11,1,11,1,11,
  	1,12,1,12,1,12,1,12,1,13,4,13,67,8,13,11,13,12,13,68,1,13,1,13,0,0,14,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	1,0,2,1,0,48,57,2,0,10,10,32,32,73,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,
  	0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,
  	1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,
  	0,0,1,29,1,0,0,0,3,32,1,0,0,0,5,36,1,0,0,0,7,38,1,0,0,0,9,40,1,0,0,0,
  	11,42,1,0,0,0,13,44,1,0,0,0,15,46,1,0,0,0,17,48,1,0,0,0,19,51,1,0,0,0,
  	21,54,1,0,0,0,23,58,1,0,0,0,25,61,1,0,0,0,27,66,1,0,0,0,29,30,5,61,0,
  	0,30,2,1,0,0,0,31,33,7,0,0,0,32,31,1,0,0,0,33,34,1,0,0,0,34,32,1,0,0,
  	0,34,35,1,0,0,0,35,4,1,0,0,0,36,37,5,82,0,0,37,6,1,0,0,0,38,39,5,43,0,
  	0,39,8,1,0,0,0,40,41,5,45,0,0,41,10,1,0,0,0,42,43,5,42,0,0,43,12,1,0,
  	0,0,44,45,5,47,0,0,45,14,1,0,0,0,46,47,5,94,0,0,47,16,1,0,0,0,48,49,5,
  	60,0,0,49,50,5,60,0,0,50,18,1,0,0,0,51,52,5,62,0,0,52,53,5,62,0,0,53,
  	20,1,0,0,0,54,55,5,97,0,0,55,56,5,110,0,0,56,57,5,100,0,0,57,22,1,0,0,
  	0,58,59,5,111,0,0,59,60,5,114,0,0,60,24,1,0,0,0,61,62,5,120,0,0,62,63,
  	5,111,0,0,63,64,5,114,0,0,64,26,1,0,0,0,65,67,7,1,0,0,66,65,1,0,0,0,67,
  	68,1,0,0,0,68,66,1,0,0,0,68,69,1,0,0,0,69,70,1,0,0,0,70,71,6,13,0,0,71,
  	28,1,0,0,0,3,0,34,68,1,6,0,0
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
