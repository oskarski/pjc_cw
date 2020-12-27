#include <iostream>

const int UNCOVERED_CELL_TYPE = -1;
const int UNCOVERED_BOMB_CELL_TYPE = -2;
const int UNCOVERED_FLAGGED_BOMB_CELL_TYPE = -3;
const int BOMB_CELL_TYPE = -4;
const int FLAG_CELL_TYPE = -5;

const int SELECT_CELL_ACTION = 0;
const int FLAG_CELL_ACTION = 1;

struct BoardConfig {
    const size_t rows_length = 5;
    const size_t columns_length = 5;
    const size_t number_of_bombs = 5;
};

struct BoardCell {
    int type = UNCOVERED_CELL_TYPE;
};

struct Board {
    const BoardConfig board_config;
    const size_t size = board_config.columns_length * board_config.rows_length;
    BoardCell *board_cells = new BoardCell[size];
};