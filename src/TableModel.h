//
// Created by Rostik on 1/4/2024.
//

#ifndef DIAMONDSHEETS_TABLEMODEL_H
#define DIAMONDSHEETS_TABLEMODEL_H

#include <QAbstractTableModel>

class Cell;

class TableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    TableModel(QObject *parent = nullptr);

private:
    int rowCount(const QModelIndex &index) const override;

    int columnCount(const QModelIndex &index) const override;

    QVariant data(const QModelIndex& index, int role) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    QString evaluateExpression(const QString &expression, const std::shared_ptr<Cell> &cell, bool isUpdate);

    bool detectLoop(const std::shared_ptr<Cell>& cell);

    void updateCells(const std::shared_ptr<Cell>& headCell);

Q_SIGNALS:
    void cellEdited();

public Q_SLOTS:
    void setDefaultModel();

    void addRow(QModelIndex index, int offset = 0);

    void addColumn(QModelIndex index, int offset = 0);

    void deleteRow(QModelIndex index);

    void deleteColumn(QModelIndex index);

    void serialize(QTextStream& out);

    void deserialize(QTextStream& in);

private:
    const int defaultRowsCount = 100, defaultColumnsCount = 100;
    int rows, columns;
    std::vector<std::vector<std::shared_ptr<Cell>>> gridData;
};


#endif //DIAMONDSHEETS_TABLEMODEL_H
