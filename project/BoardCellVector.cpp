#include "BoardCellVector.h"

BoardCellVector::BoardCellVector(BoardConfig *board_config) {
    int size = board_config->get_number_of_columns() * board_config->get_number_of_rows();

    this->board_config = board_config;
    this->cells = vector<BoardCell *>(size);

    for (int i = 0; i < size; i++) this->cells[i] = BoardCell::create();
}

BoardCell *BoardCellVector::at(int column, int row) {
    if (!this->cell_exists(column, row)) return nullptr;

    int cell_index = (row * this->board_config->get_number_of_columns()) + column;

    return this->at_index(cell_index);
}

BoardCell *BoardCellVector::at_index(int cell_index) {
    if (!this->index_exists(cell_index)) return nullptr;

    return this->cells[cell_index];
}

int BoardCellVector::size() {
    return this->cells.size();
}

void BoardCellVector::set(int i, BoardCell *board_cell) {
    delete this->cells[i];

    this->cells[i] = board_cell;
}

bool BoardCellVector::is_bomb(int column, int row) {
    return this->cell_exists(column, row) && this->at(column, row)->contains_bomb();
}

bool BoardCellVector::is_un_flagged_bomb(int column, int row) {
    return this->is_bomb(column, row) && !this->at(column, row)->contains_flag();
}

bool BoardCellVector::is_clickable(int column, int row) {
    if (this->cell_exists(column, row) && this->at(column, row)->is_clickable()) return true;

    return false;
}

bool BoardCellVector::cell_exists(int column, int row) {
    if (column < 0 || column >= this->board_config->get_number_of_columns()) return false;
    if (row < 0 || row >= this->board_config->get_number_of_rows()) return false;

    return true;
}

bool BoardCellVector::index_exists(int index) {
    return index >= 0 && index < this->size();
}
