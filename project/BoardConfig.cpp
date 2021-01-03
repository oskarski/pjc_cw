#include "BoardConfig.h"

BoardConfig::BoardConfig(int number_of_columns, int number_of_rows, int number_of_bombs) {
    this->number_of_columns = number_of_columns;
    this->number_of_rows = number_of_rows;
    this->number_of_bombs = number_of_bombs;
}

int BoardConfig::get_number_of_columns() {
    return this->number_of_columns;
}

int BoardConfig::get_number_of_rows() {
    return this->number_of_rows;
}

int BoardConfig::get_number_of_bombs() {
    return this->number_of_bombs;
}