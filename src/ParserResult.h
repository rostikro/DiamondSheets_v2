//
// Created by Rostik on 1/6/2024.
//

#ifndef DIAMONDSHEETS_PARSERRESULT_H
#define DIAMONDSHEETS_PARSERRESULT_H

#include <QString>
#include <utility>

struct ParserResult
{
    enum ResultType
    {
        ERROR,
        DOUBLE,
        BOOL
    };

    ParserResult(double value, ResultType type = DOUBLE)
        : value(value), type(type) {}

    ParserResult(QString error)
        : error(std::move(error)), type(ERROR) {}

    ResultType type;
    double value;
    QString error;
};

#endif //DIAMONDSHEETS_PARSERRESULT_H
