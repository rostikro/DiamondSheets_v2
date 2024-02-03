
// Generated from ../grammar/DiamondSheets.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DiamondSheetsParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, MULTIPLY = 4, DIVIDE = 5, INTDIV = 6, 
    MOD = 7, PLUS = 8, MINUS = 9, L_COMP = 10, R_COMP = 11, EQ_COMP = 12, 
    N_EQ_COMP = 13, L_EQ_COMP = 14, R_EQ_COMP = 15, CELLID = 16, NAME = 17, 
    NUMBER = 18, WS = 19
  };

  enum {
    RuleExpression = 0
  };

  explicit DiamondSheetsParser(antlr4::TokenStream *input);

  DiamondSheetsParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~DiamondSheetsParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ExpressionContext; 

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PowerExprContext : public ExpressionContext {
  public:
    PowerExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddSubExprContext : public ExpressionContext {
  public:
    AddSubExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompExprContext : public ExpressionContext {
  public:
    CompExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *L_COMP();
    antlr4::tree::TerminalNode *R_COMP();
    antlr4::tree::TerminalNode *EQ_COMP();
    antlr4::tree::TerminalNode *N_EQ_COMP();
    antlr4::tree::TerminalNode *L_EQ_COMP();
    antlr4::tree::TerminalNode *R_EQ_COMP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CellIdAtomExprContext : public ExpressionContext {
  public:
    CellIdAtomExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *CELLID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivModExprContext : public ExpressionContext {
  public:
    MulDivModExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *INTDIV();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesisExprContext : public ExpressionContext {
  public:
    ParenthesisExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumericAtomExprContext : public ExpressionContext {
  public:
    NumericAtomExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *NUMBER();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

