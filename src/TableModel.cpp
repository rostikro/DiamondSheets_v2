//
// Created by Rostik on 1/4/2024.
//

#include <queue>
#include <QMessageBox>
#include "TableModel.h"

#include "antlr4-runtime.h"
#include "grammar/DiamondSheetsLexer.h"
#include "grammar/DiamondSheetsParser.h"

#include "Cell.h"
#include "ExpressionParser.h"
#include "ParserResult.h"
#include "Utils.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    setDefaultModel();
}

int TableModel::rowCount(const QModelIndex &index) const
{
    return rows;
}

int TableModel::columnCount(const QModelIndex &index) const
{
    return columns;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (checkIndex(index))
    {
        if (role == Qt::DisplayRole)
            return gridData[index.row()][index.column()]->getValue();
        if (role == Qt::EditRole)
            return gridData[index.row()][index.column()]->getExpression();
    }

    return {};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
            return utils::convertIndexToLetterIndex(section);

        return section + 1;
    }

    return {};
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole || !checkIndex(index))
        return false;

    // Clear all references because we don't keep track of whether they have been removed from the new expression
    for (auto &cell : gridData[index.row()][index.column()]->getReferenced())
    {
        cell->deleteRef(gridData[index.row()][index.column()]);
    }
    gridData[index.row()][index.column()]->clearReferenced();

    // Adding new value to the cell
    gridData[index.row()][index.column()]->setExpression(value.toString());
    gridData[index.row()][index.column()]->setValue(value.toString());

    // Checking if the expression should be evaluated
    if (value.toString().size() > 0)
        if (value.toString()[0] == '=')
            gridData[index.row()][index.column()]->setValue(
                    evaluateExpression(value.toString().mid(1),
                                       gridData[index.row()][index.column()], false));

    // Checking that references don't create loop
    if (detectLoop(gridData[index.row()][index.column()]))
    {
        gridData[index.row()][index.column()]->setValue(Cell::refErrorText);

        std::queue<std::shared_ptr<Cell>> refsQueue;
        refsQueue.push(gridData[index.row()][index.column()]);

        while (!refsQueue.empty())
        {
            auto nextRef = refsQueue.front();
            refsQueue.pop();

            for (auto &ref : nextRef->getRefs()) {
                if (ref->getValue() == Cell::refErrorText)
                    break;

                ref->setValue(Cell::refErrorText);
                refsQueue.push(ref);
            }
        }

        return true;
    }

    // Updating cells, that refers to this cell
    updateCells(gridData[index.row()][index.column()]);

    Q_EMIT cellEdited();
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

void TableModel::setDefaultModel()
{
    gridData.clear();
    rows = defaultRowsCount;
    columns = defaultColumnsCount;

    for (int i = 0; i < rows; i++)
    {
        std::vector<std::shared_ptr<Cell>> row;
        for (int j = 0; j < columns; j++)
        {
            row.push_back(std::make_shared<Cell>());
        }
        gridData.push_back(row);
    }
}

QString TableModel::evaluateExpression(const QString &expression, const std::shared_ptr<Cell> &cell, bool isUpdate)
{
    antlr4::ANTLRInputStream input(expression.toStdString());
    DiamondSheetsLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    DiamondSheetsParser parser(&tokens);
    DiamondSheetsParser::ExpressionContext* expressionContext = parser.expression();

    ExpressionParser expressionParser(&gridData,cell, isUpdate);

    auto result_any = expressionParser.visit(expressionContext);

    if (!result_any.has_value())
        return Cell::errorText;

    auto result = std::any_cast<ParserResult>(result_any);

    if (result.type == ParserResult::ERROR)
        return result.error;

    if (result.type == ParserResult::DOUBLE)
        return QString::number(result.value);

    if (result.type == ParserResult::BOOL)
        return result.value ? Cell::trueText : Cell::falseText;

    return {};
}

bool TableModel::detectLoop(const std::shared_ptr<Cell> &cell)
{
    cell->visited = true;

    for (auto &ref : cell->getReferenced())
    {
        if (ref->visited)
        {
            ref->visited = false;
            return true;
        }

        if (detectLoop(ref))
            return true;
    }

    cell->visited = false;
    return false;
}

void TableModel::updateCells(const std::shared_ptr<Cell> &headCell)
{
    std::queue<std::shared_ptr<Cell>> updateQueue;

    for (auto &ref : headCell->getRefs())
        updateQueue.push(ref);

    while (!updateQueue.empty())
    {
        auto cell = updateQueue.front();
        updateQueue.pop();

        if (detectLoop(cell))
            continue;

        cell->setValue(evaluateExpression(cell->getExpression().mid(1), cell, true));

        for (auto &ref : cell->getRefs())
            updateQueue.push(ref);
    }
}

void TableModel::addRow(QModelIndex index, int offset)
{
    // If the user called the context menu outside the table (index = {-1, -1}),
    // then a new row must be added to the end of the table
    if (index.row() == -1)
        offset = rows + 1;

    std::vector<std::shared_ptr<Cell>> row;
    for (int i = 0; i < columns; i++)
    {
        row.push_back(std::make_shared<Cell>());
    }
    gridData.insert(gridData.begin() + (index.row() + offset), row);
    rows++;

    // Since the index of the cells below the new row has changed,
    // we need to update this indexes in the cells that refer to cells under the new row
    for (int i = index.row() + offset + 1; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // If there are cells that refer to this cell, then we change the index in the expression of those cells
            for (auto &ref : gridData[i][j]->getRefs())
            {
                auto columnIndex = utils::convertIndexToLetterIndex(j);
                ref->setExpression(ref->getExpression().replace(columnIndex + QString::number(i), columnIndex + QString::number(i + 1)));
            }
        }
    }

    Q_EMIT layoutChanged();
}

void TableModel::addColumn(QModelIndex index, int offset)
{
    // If the user called the context menu outside the table (index = {-1, -1}),
    // then a new column must be added to the end of the table
    if (index.column() == -1)
        offset = columns + 1;

    for (int i = 0; i < rows; i++)
    {
        gridData[i].insert(gridData[i].begin() + (index.column() + offset), std::make_shared<Cell>());
    }
    columns++;

    // Since the index of the cells to the right of the new column has changed,
    // we need to update this indexes in the cells that refer to cells to the right of the new column
    for (int i = 0; i < rows; i++)
    {
        for (int j = index.column() + offset + 1; j < columns; j++)
        {
            // If there are cells that refer to this cell, then we change the index in the expression of those cells
            for (auto &ref : gridData[i][j]->getRefs())
            {
                auto rowIndex = QString::number(i + 1);
                ref->setExpression(ref->getExpression().replace(
                        utils::convertIndexToLetterIndex(j - 1) + rowIndex,
                        utils::convertIndexToLetterIndex(j) + rowIndex));
            }
        }
    }

    Q_EMIT layoutChanged();
}

void TableModel::deleteRow(QModelIndex index)
{
    if (index.row() == -1)
    {
        QMessageBox::information(nullptr, "Error", "Invalid index of the row!");
        return;
    }

    if (rows == 1)
    {
        QMessageBox::information(nullptr, "Error", "Cannot delete the last row!");
        return;
    }

    // If there are cells, that refers to cell, that are going to be deleted,
    // then we need to set ref error in these cells
    for (int i = 0; i < columns; i++)
    {
        for (auto& ref : gridData[index.row()][i]->getRefs())
        {
            ref->setExpression(ref->getExpression().replace(utils::convertIndexToLetterIndex(i) + QString::number(index.row() + 1), Cell::refErrorText));
            ref->setValue(Cell::refErrorText);
        }
    }
    gridData.erase(gridData.begin() + index.row());
    rows--;

    // Since the index of the cells below the new row has changed,
    // we need to update this indexes in the cells that refer to cells under the new row
    for (int i = index.row(); i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // If there are cells that refer to this cell, then we change the index in the expression of those cells
            for (auto& ref : gridData[i][j]->getRefs())
            {
                auto columnIndex = utils::convertIndexToLetterIndex(j);
                ref->setExpression(ref->getExpression().replace(columnIndex + QString::number(i + 2), columnIndex + QString::number(i + 1)));
            }
        }
    }

    Q_EMIT layoutChanged();
}

void TableModel::deleteColumn(QModelIndex index)
{
    if (index.column() == -1)
    {
        QMessageBox::information(nullptr, "Error", "Invalid index of the column!");
        return;
    }

    if (columns == 1)
    {
        QMessageBox::information(nullptr, "Error", "Cannot delete the last column!");
        return;
    }

    // If there are cells, that refers to cell, that are going to be deleted,
    // then we need to set ref error in these cells
    for (int i = 0; i < rows; i++)
    {
        for (auto& ref : gridData[i][index.column()]->getRefs())
        {
            ref->setExpression(ref->getExpression().replace(utils::convertIndexToLetterIndex(index.column()) + QString::number(i + 1), Cell::refErrorText));
            ref->setValue(Cell::refErrorText);
        }
        gridData[i].erase(gridData[i].begin() + index.column());
    }
    columns--;

    // Since the index of the cells to the right of the new column has changed,
    // we need to update this indexes in the cells that refer to cells to the right of the new column
    for (int i = 0; i < rows; i++)
    {
        for (int j = index.column(); j < columns; j++)
        {
            // If there are cells that refer to this cell, then we change the index in the expression of those cells
            for (auto& ref : gridData[i][j]->getRefs())
            {
                auto rowIndex = QString::number(i + 1);
                ref->setExpression(ref->getExpression().replace(utils::convertIndexToLetterIndex(j + 1) + rowIndex, utils::convertIndexToLetterIndex(j) + rowIndex));
            }
        }
    }

    Q_EMIT layoutChanged();
}

void TableModel::serialize(QTextStream &out)
{
    for (int i = 0; i < gridData.size(); i++)
    {
        if (i != 0) out << "\n";
        for (auto& cell : gridData[i])
        {
            if (!cell->getExpression().isEmpty())
                out << cell->getExpression();
            out << ",";
        }
    }
}

void TableModel::deserialize(QTextStream &in)
{
    gridData.clear();
    int rowIndex = 0;

    while(!in.atEnd())
    {
        std::vector<std::shared_ptr<Cell>> data;

        int columnIndex = 0;
        int delimiterIndex = -1;

        QChar delimiter = ',';

        auto row = in.readLine();
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i] == delimiter)
            {
                if (delimiterIndex + 1 == i)
                {
                    delimiterIndex = i;
                    columnIndex++;
                    data.push_back(std::make_shared<Cell>());
                    continue;
                }

                QString expression = row.mid(delimiterIndex + 1, i - delimiterIndex - 1);

                // Cell only with expression
                data.push_back(std::make_shared<Cell>(expression, ""));

                delimiterIndex = i;
                columnIndex++;
            }
        }
        rowIndex++;
        gridData.push_back(data);
    }

    // Evaluate all expressions
    int i = -1;
    for (auto& row : gridData)
    {
        i++;
        int j = -1;
        for (auto& cell : row)
        {
            j++;
            if (cell->getExpression() == nullptr) continue;
            setData(createIndex(i, j), cell->getExpression());
        }
    }

    rows = gridData.size();
    columns = gridData[0].size();

    Q_EMIT layoutChanged();
}
