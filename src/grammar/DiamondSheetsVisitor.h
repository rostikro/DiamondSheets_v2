
// Generated from ../grammar/DiamondSheets.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DiamondSheetsParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by DiamondSheetsParser.
 */
class  DiamondSheetsVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DiamondSheetsParser.
   */
    virtual std::any visitPowerExpr(DiamondSheetsParser::PowerExprContext *context) = 0;

    virtual std::any visitAddSubExpr(DiamondSheetsParser::AddSubExprContext *context) = 0;

    virtual std::any visitCompExpr(DiamondSheetsParser::CompExprContext *context) = 0;

    virtual std::any visitCellIdAtomExpr(DiamondSheetsParser::CellIdAtomExprContext *context) = 0;

    virtual std::any visitMulDivModExpr(DiamondSheetsParser::MulDivModExprContext *context) = 0;

    virtual std::any visitParenthesisExpr(DiamondSheetsParser::ParenthesisExprContext *context) = 0;

    virtual std::any visitNumericAtomExpr(DiamondSheetsParser::NumericAtomExprContext *context) = 0;


};

