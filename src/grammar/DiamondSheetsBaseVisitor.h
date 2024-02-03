
// Generated from ../grammar/DiamondSheets.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DiamondSheetsVisitor.h"


/**
 * This class provides an empty implementation of DiamondSheetsVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DiamondSheetsBaseVisitor : public DiamondSheetsVisitor {
public:

  virtual std::any visitPowerExpr(DiamondSheetsParser::PowerExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSubExpr(DiamondSheetsParser::AddSubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompExpr(DiamondSheetsParser::CompExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCellIdAtomExpr(DiamondSheetsParser::CellIdAtomExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDivModExpr(DiamondSheetsParser::MulDivModExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesisExpr(DiamondSheetsParser::ParenthesisExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericAtomExpr(DiamondSheetsParser::NumericAtomExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

