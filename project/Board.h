#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "BoardConfig.h"
#include "BoardCellVector.h"

class Board {
private:
    BoardConfig *board_config;
    BoardCellVector *board_cells;

public:
    Board(BoardConfig *board_config);

    void render();

    void toggle_flag(int column, int row);

    bool select_cell(int column, int row);

    bool flag_nearest_bomb(int column, int row, int distance = 1);

    bool is_cell_clickable(int column, int row);

    bool is_game_won();

private:
    void plant_bombs();

    void uncover_cell(int column, int row);

    int count_nearby_bombs(int column, int row);

    void detonate_all_bombs();
};


#endif
