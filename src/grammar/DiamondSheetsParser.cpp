
// Generated from ../grammar/DiamondSheets.g4 by ANTLR 4.13.1


#include "DiamondSheetsVisitor.h"

#include "DiamondSheetsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct DiamondSheetsParserStaticData final {
  DiamondSheetsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DiamondSheetsParserStaticData(const DiamondSheetsParserStaticData&) = delete;
  DiamondSheetsParserStaticData(DiamondSheetsParserStaticData&&) = delete;
  DiamondSheetsParserStaticData& operator=(const DiamondSheetsParserStaticData&) = delete;
  DiamondSheetsParserStaticData& operator=(DiamondSheetsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag diamondsheetsParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
DiamondSheetsParserStaticData *diamondsheetsParserStaticData = nullptr;

void diamondsheetsParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (diamondsheetsParserStaticData != nullptr) {
    return;
  }
#else
  assert(diamondsheetsParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DiamondSheetsParserStaticData>(
    std::vector<std::string>{
      "expression"
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
  	4,1,19,29,2,0,7,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,10,8,0,1,0,1,0,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,5,0,24,8,0,10,0,12,0,27,9,0,1,0,0,
  	1,0,1,0,0,3,1,0,4,7,1,0,8,9,1,0,10,15,33,0,9,1,0,0,0,2,3,6,0,-1,0,3,4,
  	5,1,0,0,4,5,3,0,0,0,5,6,5,2,0,0,6,10,1,0,0,0,7,10,5,18,0,0,8,10,5,16,
  	0,0,9,2,1,0,0,0,9,7,1,0,0,0,9,8,1,0,0,0,10,25,1,0,0,0,11,12,10,6,0,0,
  	12,13,5,3,0,0,13,24,3,0,0,6,14,15,10,5,0,0,15,16,7,0,0,0,16,24,3,0,0,
  	6,17,18,10,4,0,0,18,19,7,1,0,0,19,24,3,0,0,5,20,21,10,3,0,0,21,22,7,2,
  	0,0,22,24,3,0,0,4,23,11,1,0,0,0,23,14,1,0,0,0,23,17,1,0,0,0,23,20,1,0,
  	0,0,24,27,1,0,0,0,25,23,1,0,0,0,25,26,1,0,0,0,26,1,1,0,0,0,27,25,1,0,
  	0,0,3,9,23,25
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  diamondsheetsParserStaticData = staticData.release();
}

}

DiamondSheetsParser::DiamondSheetsParser(TokenStream *input) : DiamondSheetsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

DiamondSheetsParser::DiamondSheetsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  DiamondSheetsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *diamondsheetsParserStaticData->atn, diamondsheetsParserStaticData->decisionToDFA, diamondsheetsParserStaticData->sharedContextCache, options);
}

DiamondSheetsParser::~DiamondSheetsParser() {
  delete _interpreter;
}

const atn::ATN& DiamondSheetsParser::getATN() const {
  return *diamondsheetsParserStaticData->atn;
}

std::string DiamondSheetsParser::getGrammarFileName() const {
  return "DiamondSheets.g4";
}

const std::vector<std::string>& DiamondSheetsParser::getRuleNames() const {
  return diamondsheetsParserStaticData->ruleNames;
}

const dfa::Vocabulary& DiamondSheetsParser::getVocabulary() const {
  return diamondsheetsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DiamondSheetsParser::getSerializedATN() const {
  return diamondsheetsParserStaticData->serializedATN;
}


//----------------- ExpressionContext ------------------------------------------------------------------

DiamondSheetsParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DiamondSheetsParser::ExpressionContext::getRuleIndex() const {
  return DiamondSheetsParser::RuleExpression;
}

void DiamondSheetsParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PowerExprContext ------------------------------------------------------------------

std::vector<DiamondSheetsParser::ExpressionContext *> DiamondSheetsParser::PowerExprContext::expression() {
  return getRuleContexts<DiamondSheetsParser::ExpressionContext>();
}

DiamondSheetsParser::ExpressionContext* DiamondSheetsParser::PowerExprContext::expression(size_t i) {
  return getRuleContext<DiamondSheetsParser::ExpressionContext>(i);
}

DiamondSheetsParser::PowerExprContext::PowerExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any DiamondSheetsParser::PowerExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DiamondSheetsVisitor*>(visitor))
    return parserVisitor->visitPowerExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<DiamondSheetsParser::ExpressionContext *> DiamondSheetsParser::AddSubExprContext::expression() {
  return getRuleContexts<DiamondSheetsParser::ExpressionContext>();
}

DiamondSheetsParser::ExpressionContext* DiamondSheetsParser::AddSubExprContext::expression(size_t i) {
  return getRuleContext<DiamondSheetsParser::ExpressionContext>(i);
}

tree::TerminalNode* DiamondSheetsParser::AddSubExprContext::PLUS() {
  return getToken(DiamondSheetsParser::PLUS, 0);
}

tree::TerminalNode* DiamondSheetsParser::AddSubExprContext::MINUS() {
  return getToken(DiamondSheetsParser::MINUS, 0);
}

DiamondSheetsParser::AddSubExprContext::AddSubExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any DiamondSheetsParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DiamondSheetsVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompExprContext ------------------------------------------------------------------

std::vector<DiamondSheetsParser::ExpressionContext *> DiamondSheetsParser::CompExprContext::expression() {
  return getRuleContexts<DiamondSheetsParser::ExpressionContext>();
}

DiamondSheetsParser::ExpressionContext* DiamondSheetsParser::CompExprContext::expression(size_t i) {
  return getRuleContext<DiamondSheetsParser::ExpressionContext>(i);
}

tree::TerminalNode* DiamondSheetsParser::CompExprContext::L_COMP() {
  return getToken(DiamondSheetsParser::L_COMP, 0);
}

tree::TerminalNode* DiamondSheetsParser::CompExprContext::R_COMP() {
  return getToken(DiamondSheetsParser::R_COMP, 0);
}

tree::TerminalNode* DiamondSheetsParser::CompExprContext::EQ_COMP() {
  return getToken(DiamondSheetsParser::EQ_COMP, 0);
}

tree::TerminalNode* DiamondSheetsParser::CompExprContext::N_EQ_COMP() {
  return getToken(DiamondSheetsParser::N_EQ_COMP, 0);
}

tree::TerminalNode* DiamondSheetsParser::CompExprContext::L_EQ_COMP() {
  return getToken(DiamondSheetsParser::L_EQ_COMP, 0);
}

tree::TerminalNode* DiamondSheetsParser::CompExprContext::R_EQ_COMP() {
  return getToken(DiamondSheetsParser::R_EQ_COMP, 0);
}

DiamondSheetsParser::CompExprContext::CompExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any DiamondSheetsParser::CompExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DiamondSheetsVisitor*>(visitor))
    return parserVisitor->visitCompExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CellIdAtomExprContext ------------------------------------------------------------------

tree::TerminalNode* DiamondSheetsParser::CellIdAtomExprContext::CELLID() {
  return getToken(DiamondSheetsParser::CELLID, 0);
}

DiamondSheetsParser::CellIdAtomExprContext::CellIdAtomExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any DiamondSheetsParser::CellIdAtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DiamondSheetsVisitor*>(visitor))
    return parserVisitor->visitCellIdAtomExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivModExprContext ------------------------------------------------------------------

std::vector<DiamondSheetsParser::ExpressionContext *> DiamondSheetsParser::MulDivModExprContext::expression() {
  return getRuleContexts<DiamondSheetsParser::ExpressionContext>();
}

DiamondSheetsParser::ExpressionContext* DiamondSheetsParser::MulDivModExprContext::expression(size_t i) {
  return getRuleContext<DiamondSheetsParser::ExpressionContext>(i);
}

tree::TerminalNode* DiamondSheetsParser::MulDivModExprContext::MULTIPLY() {
  return getToken(DiamondSheetsParser::MULTIPLY, 0);
}

tree::TerminalNode* DiamondSheetsParser::MulDivModExprContext::DIVIDE() {
  return getToken(DiamondSheetsParser::DIVIDE, 0);
}

tree::TerminalNode* DiamondSheetsParser::MulDivModExprContext::MOD() {
  return getToken(DiamondSheetsParser::MOD, 0);
}

tree::TerminalNode* DiamondSheetsParser::MulDivModExprContext::INTDIV() {
  return getToken(DiamondSheetsParser::INTDIV, 0);
}

DiamondSheetsParser::MulDivModExprContext::MulDivModExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any DiamondSheetsParser::MulDivModExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DiamondSheetsVisitor*>(visitor))
    return parserVisitor->visitMulDivModExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisExprContext ------------------------------------------------------------------

DiamondSheetsParser::ExpressionContext* DiamondSheetsParser::ParenthesisExprContext::expression() {
  return getRuleContext<DiamondSheetsParser::ExpressionContext>(0);
}

DiamondSheetsParser::ParenthesisExprContext::ParenthesisExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any DiamondSheetsParser::ParenthesisExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DiamondSheetsVisitor*>(visitor))
    return parserVisitor->visitParenthesisExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumericAtomExprContext ------------------------------------------------------------------

tree::TerminalNode* DiamondSheetsParser::NumericAtomExprContext::NUMBER() {
  return getToken(DiamondSheetsParser::NUMBER, 0);
}

DiamondSheetsParser::NumericAtomExprContext::NumericAtomExprContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any DiamondSheetsParser::NumericAtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DiamondSheetsVisitor*>(visitor))
    return parserVisitor->visitNumericAtomExpr(this);
  else
    return visitor->visitChildren(this);
}

DiamondSheetsParser::ExpressionContext* DiamondSheetsParser::expression() {
   return expression(0);
}

DiamondSheetsParser::ExpressionContext* DiamondSheetsParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DiamondSheetsParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  DiamondSheetsParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, DiamondSheetsParser::RuleExpression, precedence);

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
    setState(9);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DiamondSheetsParser::T__0: {
        _localctx = _tracker.createInstance<ParenthesisExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(3);
        match(DiamondSheetsParser::T__0);
        setState(4);
        expression(0);
        setState(5);
        match(DiamondSheetsParser::T__1);
        break;
      }

      case DiamondSheetsParser::NUMBER: {
        _localctx = _tracker.createInstance<NumericAtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(7);
        match(DiamondSheetsParser::NUMBER);
        break;
      }

      case DiamondSheetsParser::CELLID: {
        _localctx = _tracker.createInstance<CellIdAtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(8);
        match(DiamondSheetsParser::CELLID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(25);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(23);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<PowerExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(11);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(12);
          match(DiamondSheetsParser::T__2);
          setState(13);
          expression(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulDivModExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(14);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(15);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 240) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(16);
          expression(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(17);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(18);
          _la = _input->LA(1);
          if (!(_la == DiamondSheetsParser::PLUS

          || _la == DiamondSheetsParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(19);
          expression(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<CompExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(20);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(21);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 64512) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(22);
          expression(4);
          break;
        }

        default:
          break;
        } 
      }
      setState(27);
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

bool DiamondSheetsParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DiamondSheetsParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

void DiamondSheetsParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  diamondsheetsParserInitialize();
#else
  ::antlr4::internal::call_once(diamondsheetsParserOnceFlag, diamondsheetsParserInitialize);
#endif
}
