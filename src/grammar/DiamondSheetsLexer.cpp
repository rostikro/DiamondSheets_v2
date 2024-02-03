
// Generated from ../grammar/DiamondSheets.g4 by ANTLR 4.13.1


#include "DiamondSheetsLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct DiamondSheetsLexerStaticData final {
  DiamondSheetsLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DiamondSheetsLexerStaticData(const DiamondSheetsLexerStaticData&) = delete;
  DiamondSheetsLexerStaticData(DiamondSheetsLexerStaticData&&) = delete;
  DiamondSheetsLexerStaticData& operator=(const DiamondSheetsLexerStaticData&) = delete;
  DiamondSheetsLexerStaticData& operator=(DiamondSheetsLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag diamondsheetslexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
DiamondSheetsLexerStaticData *diamondsheetslexerLexerStaticData = nullptr;

void diamondsheetslexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (diamondsheetslexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(diamondsheetslexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DiamondSheetsLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "LETTER", "DIGIT", "MULTIPLY", "DIVIDE", "INTDIV", 
      "MOD", "PLUS", "MINUS", "L_COMP", "R_COMP", "EQ_COMP", "N_EQ_COMP", 
      "L_EQ_COMP", "R_EQ_COMP", "CELLID", "NAME", "NUMBER", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'^'", "'*'", "'/'", "'//'", "'%'", "'+'", "'-'", 
      "'<'", "'>'", "'='", "'!='", "'<='", "'>='", "", "", "", "' '"
    },
    std::vector<std::string>{
      "", "", "", "", "MULTIPLY", "DIVIDE", "INTDIV", "MOD", "PLUS", "MINUS", 
      "L_COMP", "R_COMP", "EQ_COMP", "N_EQ_COMP", "L_EQ_COMP", "R_EQ_COMP", 
      "CELLID", "NAME", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,19,113,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,
  	1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,8,1,
  	8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,15,
  	1,15,1,15,1,16,1,16,1,16,1,17,4,17,83,8,17,11,17,12,17,84,1,17,4,17,88,
  	8,17,11,17,12,17,89,1,18,4,18,93,8,18,11,18,12,18,94,1,19,4,19,98,8,19,
  	11,19,12,19,99,1,19,1,19,4,19,104,8,19,11,19,12,19,105,3,19,108,8,19,
  	1,20,1,20,1,20,1,20,0,0,21,1,1,3,2,5,3,7,0,9,0,11,4,13,5,15,6,17,7,19,
  	8,21,9,23,10,25,11,27,12,29,13,31,14,33,15,35,16,37,17,39,18,41,19,1,
  	0,2,2,0,65,90,97,122,1,0,48,57,116,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,
  	0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,
  	21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,
  	0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,
  	0,1,43,1,0,0,0,3,45,1,0,0,0,5,47,1,0,0,0,7,49,1,0,0,0,9,51,1,0,0,0,11,
  	53,1,0,0,0,13,55,1,0,0,0,15,57,1,0,0,0,17,60,1,0,0,0,19,62,1,0,0,0,21,
  	64,1,0,0,0,23,66,1,0,0,0,25,68,1,0,0,0,27,70,1,0,0,0,29,72,1,0,0,0,31,
  	75,1,0,0,0,33,78,1,0,0,0,35,82,1,0,0,0,37,92,1,0,0,0,39,97,1,0,0,0,41,
  	109,1,0,0,0,43,44,5,40,0,0,44,2,1,0,0,0,45,46,5,41,0,0,46,4,1,0,0,0,47,
  	48,5,94,0,0,48,6,1,0,0,0,49,50,7,0,0,0,50,8,1,0,0,0,51,52,7,1,0,0,52,
  	10,1,0,0,0,53,54,5,42,0,0,54,12,1,0,0,0,55,56,5,47,0,0,56,14,1,0,0,0,
  	57,58,5,47,0,0,58,59,5,47,0,0,59,16,1,0,0,0,60,61,5,37,0,0,61,18,1,0,
  	0,0,62,63,5,43,0,0,63,20,1,0,0,0,64,65,5,45,0,0,65,22,1,0,0,0,66,67,5,
  	60,0,0,67,24,1,0,0,0,68,69,5,62,0,0,69,26,1,0,0,0,70,71,5,61,0,0,71,28,
  	1,0,0,0,72,73,5,33,0,0,73,74,5,61,0,0,74,30,1,0,0,0,75,76,5,60,0,0,76,
  	77,5,61,0,0,77,32,1,0,0,0,78,79,5,62,0,0,79,80,5,61,0,0,80,34,1,0,0,0,
  	81,83,3,7,3,0,82,81,1,0,0,0,83,84,1,0,0,0,84,82,1,0,0,0,84,85,1,0,0,0,
  	85,87,1,0,0,0,86,88,3,9,4,0,87,86,1,0,0,0,88,89,1,0,0,0,89,87,1,0,0,0,
  	89,90,1,0,0,0,90,36,1,0,0,0,91,93,3,7,3,0,92,91,1,0,0,0,93,94,1,0,0,0,
  	94,92,1,0,0,0,94,95,1,0,0,0,95,38,1,0,0,0,96,98,3,9,4,0,97,96,1,0,0,0,
  	98,99,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,0,100,107,1,0,0,0,101,103,5,
  	46,0,0,102,104,3,9,4,0,103,102,1,0,0,0,104,105,1,0,0,0,105,103,1,0,0,
  	0,105,106,1,0,0,0,106,108,1,0,0,0,107,101,1,0,0,0,107,108,1,0,0,0,108,
  	40,1,0,0,0,109,110,5,32,0,0,110,111,1,0,0,0,111,112,6,20,0,0,112,42,1,
  	0,0,0,7,0,84,89,94,99,105,107,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  diamondsheetslexerLexerStaticData = staticData.release();
}

}

DiamondSheetsLexer::DiamondSheetsLexer(CharStream *input) : Lexer(input) {
  DiamondSheetsLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *diamondsheetslexerLexerStaticData->atn, diamondsheetslexerLexerStaticData->decisionToDFA, diamondsheetslexerLexerStaticData->sharedContextCache);
}

DiamondSheetsLexer::~DiamondSheetsLexer() {
  delete _interpreter;
}

std::string DiamondSheetsLexer::getGrammarFileName() const {
  return "DiamondSheets.g4";
}

const std::vector<std::string>& DiamondSheetsLexer::getRuleNames() const {
  return diamondsheetslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& DiamondSheetsLexer::getChannelNames() const {
  return diamondsheetslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& DiamondSheetsLexer::getModeNames() const {
  return diamondsheetslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& DiamondSheetsLexer::getVocabulary() const {
  return diamondsheetslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DiamondSheetsLexer::getSerializedATN() const {
  return diamondsheetslexerLexerStaticData->serializedATN;
}

const atn::ATN& DiamondSheetsLexer::getATN() const {
  return *diamondsheetslexerLexerStaticData->atn;
}




void DiamondSheetsLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  diamondsheetslexerLexerInitialize();
#else
  ::antlr4::internal::call_once(diamondsheetslexerLexerOnceFlag, diamondsheetslexerLexerInitialize);
#endif
}
