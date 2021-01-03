#include <iostream>

#include "InputReader.h"

using namespace std;

InputReader::InputReader(BoardConfig *board_config) {
    this->board_config = board_config;
}

int InputReader::read_column() {
    int column;

    cout << "Podaj kolumne: ";
    cin >> column;

    if (!this->is_valid_column(column)) {
        cout << "Nieprawidłowa wartość! Podaj wartość pomiędzy 1, a " << this->board_config->get_number_of_columns()
             << endl;

        return this->read_column();
    }

    return column;
}

int InputReader::read_row() {
    int row;

    cout << "Podaj wiersz: ";
    cin >> row;

    if (!this->is_valid_row(row)) {
        cout << "Nieprawidłowa wartość! Podaj wartość pomiędzy 1, a " << this->board_config->get_number_of_rows()
             << endl;

        return this->read_row();
    }

    return row;
}

BoardAction InputReader::read_action() {
    int action;

    cout << "Podaj akcje (";
    cout << BoardAction::QUIT_ACTION << " - zakoncz, ";
    cout << BoardAction::SELECT_ACTION << " - klik, ";
    cout << BoardAction::FLAG_ACTION << " - flaga";
    cout << "): ";
    cin >> action;

    if (!InputReader::is_valid_action(action)) {
        cout << "Nieprawidłowa wartość!" << endl;

        return read_action();
    }

    return (BoardAction) action;
}

bool InputReader::is_valid_column(int column) {
    return column >= 1 && column <= this->board_config->get_number_of_columns();
}

bool InputReader::is_valid_row(int row) {
    return row >= 1 && row <= this->board_config->get_number_of_rows();
}

bool InputReader::is_valid_action(int action) {
    return action == BoardAction::FLAG_ACTION || action == BoardAction::SELECT_ACTION ||
           action == BoardAction::QUIT_ACTION;
}
