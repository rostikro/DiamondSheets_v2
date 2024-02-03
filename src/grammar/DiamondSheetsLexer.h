
// Generated from ../grammar/DiamondSheets.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DiamondSheetsLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, MULTIPLY = 4, DIVIDE = 5, INTDIV = 6, 
    MOD = 7, PLUS = 8, MINUS = 9, L_COMP = 10, R_COMP = 11, EQ_COMP = 12, 
    N_EQ_COMP = 13, L_EQ_COMP = 14, R_EQ_COMP = 15, CELLID = 16, NAME = 17, 
    NUMBER = 18, WS = 19
  };

  explicit DiamondSheetsLexer(antlr4::CharStream *input);

  ~DiamondSheetsLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

