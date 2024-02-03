//
// Created by Rostik on 1/4/2024.
//

#ifndef DIAMONDSHEETS_CELL_H
#define DIAMONDSHEETS_CELL_H

#include <QString>
#include <utility>

class Cell {
public:
    Cell() = default;

    Cell(QString expression, QString value)
        : expression(std::move(expression)), value(std::move(value)) {}

    void setExpression(const QString &expr) { expression = expr; }

    void setValue(const QString &val) { value = val; }

    QString getExpression() const { return expression; }

    QString getValue() const { return value; }

    void addRef(const std::shared_ptr<Cell> &cell) { refs.push_back(cell); }

    void deleteRef(const std::shared_ptr<Cell> &cell) { std::erase(refs, cell); }

    std::vector<std::shared_ptr<Cell>>& getRefs() { return refs; }

    void addReferenced(const std::shared_ptr<Cell> &cell) { referenced.push_back(cell); }

    void clearReferenced() { referenced.clear(); }

    std::vector<std::shared_ptr<Cell>>& getReferenced() { return referenced; }

    bool isReferenced(const std::shared_ptr<Cell> &cell) { return std::find(referenced.begin(), referenced.end(), cell) != referenced.end(); }

public:
    static const QString errorText;
    static const QString refErrorText;
    static const QString trueText;
    static const QString falseText;

    bool visited = false;

private:
    QString expression;
    QString value;

    std::vector<std::shared_ptr<Cell>> refs; // Cells that reference this cell
    std::vector<std::shared_ptr<Cell>> referenced; // Cells that this cell refers to
};


#endif //DIAMONDSHEETS_CELL_H
