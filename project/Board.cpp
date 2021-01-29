#include <iostream>

#include "Board.h"

using namespace std;

Board::Board(BoardConfig *board_config) {
    this->board_config = board_config;
    this->board_cells = new BoardCellVector(board_config);

    this->plant_bombs();
}

void Board::render() {
    for (int row = 0; row < this->board_config->get_number_of_rows(); row++) {
        for (int column = 0; column < this->board_config->get_number_of_columns(); column++) {
            this->board_cells->at(column, row)->render();
        }

        cout << endl;
    }

    cout << endl;
}

void Board::toggle_flag(int column, int row) {
    this->board_cells->at(column, row)->toggle_flag();
}

bool Board::select_cell(int column, int row) {
    if (this->board_cells->is_bomb(column, row)) {
        this->detonate_all_bombs();
        return true;
    }

    this->uncover_cell(column, row);

    return false;
}

void Board::uncover_cell(int column, int row) {
    if (!this->is_cell_clickable(column, row)) return;

    int nearby_bombs = this->count_nearby_bombs(column, row);

    this->board_cells->at(column, row)->uncover(nearby_bombs);

    if (nearby_bombs != 0) return;

    this->uncover_cell(column, row - 1);
    this->uncover_cell(column + 1, row - 1);
    this->uncover_cell(column + 1, row);
    this->uncover_cell(column + 1, row + 1);
    this->uncover_cell(column, row + 1);
    this->uncover_cell(column - 1, row + 1);
    this->uncover_cell(column - 1, row);
    this->uncover_cell(column - 1, row - 1);
}

int Board::count_nearby_bombs(int column, int row) {
    int bombs_counter = 0;

    if (this->board_cells->is_bomb(column, row - 1)) bombs_counter++;
    if (this->board_cells->is_bomb(column + 1, row - 1)) bombs_counter++;
    if (this->board_cells->is_bomb(column + 1, row)) bombs_counter++;
    if (this->board_cells->is_bomb(column + 1, row + 1)) bombs_counter++;
    if (this->board_cells->is_bomb(column, row + 1)) bombs_counter++;
    if (this->board_cells->is_bomb(column - 1, row + 1)) bombs_counter++;
    if (this->board_cells->is_bomb(column - 1, row)) bombs_counter++;
    if (this->board_cells->is_bomb(column - 1, row - 1)) bombs_counter++;

    return bombs_counter;
}

bool Board::flag_nearest_bomb(int column, int row, int distance) {
    int leftX = column - distance;
    int rightX = column + distance;
    int topY = row - distance;
    int bottomY = row + distance;
    int x = leftX;
    int y = topY;

    // TOP ROW
    while (x <= rightX) {
        if (this->board_cells->is_un_flagged_bomb(x, y)) {
            this->board_cells->at(x, y)->toggle_flag();
            return true;
        }

        x++;
    }

    x = rightX;
    y = topY;

    // RIGHT COLUMN
    while (y <= bottomY) {
        if (this->board_cells->is_un_flagged_bomb(x, y)) {
            this->board_cells->at(x, y)->toggle_flag();
            return true;
        }

        y++;
    }

    x = rightX;
    y = bottomY;

    // BOTTOM ROW
    while (x >= leftX) {
        if (this->board_cells->is_un_flagged_bomb(x, y)) {
            this->board_cells->at(x, y)->toggle_flag();
            return true;
        }

        x--;
    }

    x = leftX;
    y = bottomY;

    // LEFT COLUMN
    while (y >= topY) {
        if (this->board_cells->is_un_flagged_bomb(x, y)) {
            this->board_cells->at(x, y)->toggle_flag();
            return true;
        }

        y--;
    }

    return this->flag_nearest_bomb(column, row, distance + 1);
}

bool Board::is_cell_clickable(int column, int row) {
    return this->board_cells->is_clickable(column, row);
}

void Board::plant_bombs() {
    srand((int) time(nullptr));
    int number_of_not_planted_bombs = this->board_config->get_number_of_bombs();

    while (number_of_not_planted_bombs > 0) {
        int random_index = rand() % this->board_cells->size();

        if (!this->board_cells->at_index(random_index)->contains_bomb()) {
            this->board_cells->set(random_index, BoardCell::create_as_bomb());
            number_of_not_planted_bombs--;
        }
    }
}

void Board::detonate_all_bombs() {
    for (int i = 0; i < this->board_cells->size(); i++) {
        this->board_cells->at_index(i)->detonate();
    }
}

bool Board::is_game_won() {
    for (int i = 0; i < this->board_cells->size(); i++) {
        if (!this->board_cells->at_index(i)->is_in_win_state()) return false;
    }

    return true;
}
