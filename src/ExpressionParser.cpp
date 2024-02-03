//
// Created by Rostik on 1/6/2024.
//

#include "ExpressionParser.h"
#include "ParserResult.h"
#include "Cell.h"
#include "Utils.h"

std::any ExpressionParser::visitPowerExpr(DiamondSheetsParser::PowerExprContext *ctx)
{
    auto l_any = visit(ctx->expression(0));
    auto r_any = visit(ctx->expression(1));

    if (!l_any.has_value() || !r_any.has_value())
        return ParserResult(Cell::errorText);

    auto l = std::any_cast<ParserResult>(l_any);
    if (l.type == ParserResult::ERROR)
        return l;

    auto r = std::any_cast<ParserResult>(r_any);
    if (r.type == ParserResult::ERROR)
        return r;

    return ParserResult(pow(l.value, r.value));
}

std::any ExpressionParser::visitAddSubExpr(DiamondSheetsParser::AddSubExprContext *ctx)
{
    auto l_any = visit(ctx->expression(0));
    auto r_any = visit(ctx->expression(1));

    if (!l_any.has_value() || !r_any.has_value())
        return ParserResult(Cell::errorText);

    auto l = std::any_cast<ParserResult>(l_any);
    if (l.type == ParserResult::ERROR)
        return l;

    auto r = std::any_cast<ParserResult>(r_any);
    if (r.type == ParserResult::ERROR)
        return r;

    if (ctx->PLUS() != nullptr)
        return ParserResult(l.value + r.value);

    if (ctx->MINUS() != nullptr)
        return ParserResult(l.value - r.value);

    return {};
}

std::any ExpressionParser::visitCompExpr(DiamondSheetsParser::CompExprContext *ctx)
{
    auto l_any = visit(ctx->expression(0));
    auto r_any = visit(ctx->expression(1));

    if (!l_any.has_value() || !r_any.has_value())
        return ParserResult(Cell::errorText);

    auto l = std::any_cast<ParserResult>(l_any);
    if (l.type == ParserResult::ERROR)
        return l;

    auto r = std::any_cast<ParserResult>(r_any);
    if (r.type == ParserResult::ERROR)
        return r;

    if (ctx->L_COMP() != nullptr)
        return ParserResult(l.value < r.value, ParserResult::BOOL);

    if (ctx->R_COMP() != nullptr)
        return ParserResult(l.value > r.value, ParserResult::BOOL);

    if (ctx->EQ_COMP() != nullptr)
        return ParserResult(l.value == r.value, ParserResult::BOOL);

    if (ctx->N_EQ_COMP() != nullptr)
        return ParserResult(l.value != r.value, ParserResult::BOOL);

    if (ctx->L_EQ_COMP() != nullptr)
        return ParserResult(l.value <= r.value, ParserResult::BOOL);

    if (ctx->R_EQ_COMP() != nullptr)
        return ParserResult(l.value >= r.value, ParserResult::BOOL);

    return {};
}

std::any ExpressionParser::visitCellIdAtomExpr(DiamondSheetsParser::CellIdAtomExprContext *ctx)
{
    auto cellId = utils::decodeCellId(ctx->getText());

    // Checking that the cellId has a valid value
    if (cellId.first < 0 || cellId.first >= pGridData->size() ||
        cellId.second < 0 || cellId.second >= pGridData->operator[](0).size())
    {
        return ParserResult(Cell::refErrorText);
    }

    QString value = pGridData->operator[](cellId.first)[cellId.second]->getValue();

    // If the cell has a new expression rather than simply updating the value
    // and the cell does not already contain a reference to that cell then a reference must be added to the cell
    if (!isUpdate && !headCell->isReferenced(pGridData->operator[](cellId.first)[cellId.second]))
    {
        pGridData->operator[](cellId.first)[cellId.second]->addRef(headCell);
        headCell->addReferenced(pGridData->operator[](cellId.first)[cellId.second]);
    }

    // Empty cell
    if (value == nullptr)
        return ParserResult(0);

    if (value == Cell::errorText)
        return ParserResult(Cell::errorText);

    if (value == Cell::refErrorText)
        return ParserResult(Cell::refErrorText);

    if (value == Cell::trueText)
        return ParserResult(1, ParserResult::BOOL);

    if (value == Cell::falseText)
        return ParserResult(0, ParserResult::BOOL);

    // Checking if value is number
    for (int i=0; i<value.size(); i++)
    {
        // If a number is preceded by a minus sign
        if (i == 0 && value[i] == '-')
            continue;

        if (!value[i].isDigit()) return ParserResult(Cell::errorText);
    }

    return ParserResult(value.toInt());
}

std::any ExpressionParser::visitMulDivModExpr(DiamondSheetsParser::MulDivModExprContext *ctx)
{
    auto l_any = visit(ctx->expression(0));
    auto r_any = visit(ctx->expression(1));

    if (!l_any.has_value() || !r_any.has_value())
        return ParserResult(Cell::errorText);

    auto l = std::any_cast<ParserResult>(l_any);
    if (l.type == ParserResult::ERROR)
        return l;

    auto r = std::any_cast<ParserResult>(r_any);
    if (r.type == ParserResult::ERROR)
        return r;

    if (ctx->MULTIPLY() != nullptr)
        return ParserResult(l.value * r.value);

    if (ctx->DIVIDE() != nullptr)
    {
        if (r.value == 0)
            return ParserResult(Cell::errorText);

        return ParserResult(l.value / r.value);
    }

    if (ctx->INTDIV() != nullptr)
    {
        if (r.value == 0)
            return ParserResult(Cell::errorText);

        return ParserResult((int)(l.value / r.value));
    }

    if (ctx->MOD() != nullptr)
        return ParserResult(std::fmod(l.value, r.value));

    return {};
}

std::any ExpressionParser::visitParenthesisExpr(DiamondSheetsParser::ParenthesisExprContext *ctx)
{
    return visit(ctx->expression());
}

std::any ExpressionParser::visitNumericAtomExpr(DiamondSheetsParser::NumericAtomExprContext *ctx)
{
    return ParserResult(std::stod(ctx->getText()));
}
