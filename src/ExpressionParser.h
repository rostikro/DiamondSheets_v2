//
// Created by Rostik on 1/6/2024.
//

#ifndef DIAMONDSHEETS_EXPRESSIONPARSER_H
#define DIAMONDSHEETS_EXPRESSIONPARSER_H

#include "grammar/DiamondSheetsBaseVisitor.h"

class Cell;

class ExpressionParser : public DiamondSheetsBaseVisitor {
public:
    ExpressionParser(std::vector<std::vector<std::shared_ptr<Cell>>> *gridData,
                     const std::shared_ptr<Cell> &headCell, bool isUpdate)
        : pGridData(gridData), headCell(headCell), isUpdate(isUpdate) {}

private:
    std::any visitPowerExpr(DiamondSheetsParser::PowerExprContext *ctx) override;

    std::any visitAddSubExpr(DiamondSheetsParser::AddSubExprContext *ctx) override;

    std::any visitCompExpr(DiamondSheetsParser::CompExprContext *ctx) override;

    std::any visitCellIdAtomExpr(DiamondSheetsParser::CellIdAtomExprContext *ctx) override;

    std::any visitMulDivModExpr(DiamondSheetsParser::MulDivModExprContext *ctx) override;

    std::any visitParenthesisExpr(DiamondSheetsParser::ParenthesisExprContext *ctx) override;

    std::any visitNumericAtomExpr(DiamondSheetsParser::NumericAtomExprContext *ctx) override;

private:
    /// If true, then the cell has not changed its expression and just needs to update its value
    bool isUpdate;
    std::shared_ptr<Cell> headCell;
    std::vector<std::vector<std::shared_ptr<Cell>>> *pGridData;
};


#endif //DIAMONDSHEETS_EXPRESSIONPARSER_H
