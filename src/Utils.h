//
// Created by Rostik on 1/5/2024.
//

#ifndef DIAMONDSHEETS_UTILS_H
#define DIAMONDSHEETS_UTILS_H

#include <QString>

namespace utils
{
    /// Converts decimal index to letter index.
    inline QString convertIndexToLetterIndex(int index)
    {
        if (index < 26)
            return QChar(index + 'A');

        return convertIndexToLetterIndex(index / 26 - 1) + convertIndexToLetterIndex(index % 26);
    }

    /// Decodes cellId in format of "A1" to columnId and rowId.\n
    /// Example: cellId = "B3", then columnId = 1, rowId = 2.
    inline std::pair<int, int> decodeCellId(const std::string &cellId)
    {
        int rowIdStart = -1;
        int columnId = 0;

        for (int i = 0; i < cellId.size(); i++)
        {
            if (std::isdigit(cellId[i]))
            {
                rowIdStart = i;
                break;
            }

            columnId = columnId * 26 + cellId[i] - 'A';
        }

        int rowId = std::stoi(cellId.substr(rowIdStart)) - 1;
        return { rowId, columnId };
    }
}

#endif //DIAMONDSHEETS_UTILS_H
