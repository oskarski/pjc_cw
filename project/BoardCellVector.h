#ifndef BOARD_VECTOR_H
#define BOARD_VECTOR_H

#include <vector>

#include "BoardConfig.h"
#include "BoardCell.h"

class BoardCellVector {
private:
    BoardConfig *board_config;
    vector<BoardCell *> cells;

public:
    BoardCellVector(BoardConfig *board_config);

    BoardCell *at(int column, int row);

    BoardCell *at_index(int index);

    int size();

    void set(int i, BoardCell *board_cell);

    bool is_bomb(int column, int row);

    bool is_clickable(int column, int row);

private:
    bool index_exists(int index);

    bool cell_exists(int column, int row);
};


#endif
