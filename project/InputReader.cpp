#include <iostream>

#include "InputReader.h"

using namespace std;

int InputReader::read_difficulty_level() {
    int difficulty_level;

    cout << "Podaj poziom trudności (1 - latwy, 2 - sredni , 3 - trudny): ";
    cin >> difficulty_level;

    if (difficulty_level < 1 || difficulty_level > 3) {
        cout << "Nieprawidłowa wartość!" << endl;
        return InputReader::read_difficulty_level();
    }

    return difficulty_level;
}

int InputReader::read_column(BoardConfig *board_config) {
    int column;

    cout << "Podaj kolumne: ";
    cin >> column;

    if (!InputReader::is_valid_column(column, board_config)) {
        cout << "Nieprawidłowa wartość! Podaj wartość pomiędzy 1, a " << board_config->get_number_of_columns()
             << endl;

        return InputReader::read_column(board_config);
    }

    return column;
}

int InputReader::read_row(BoardConfig *board_config) {
    int row;

    cout << "Podaj wiersz: ";
    cin >> row;

    if (!InputReader::is_valid_row(row, board_config)) {
        cout << "Nieprawidłowa wartość! Podaj wartość pomiędzy 1, a " << board_config->get_number_of_rows()
             << endl;

        return InputReader::read_row(board_config);
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

        return InputReader::read_action();
    }

    return (BoardAction) action;
}

bool InputReader::is_valid_column(int column, BoardConfig *board_config) {
    return column >= 1 && column <= board_config->get_number_of_columns();
}

bool InputReader::is_valid_row(int row, BoardConfig *board_config) {
    return row >= 1 && row <= board_config->get_number_of_rows();
}

bool InputReader::is_valid_action(int action) {
    return action == BoardAction::FLAG_ACTION || action == BoardAction::SELECT_ACTION ||
           action == BoardAction::QUIT_ACTION;
}
