#include <iostream>

using namespace std;

bool is_valid_coordinate(int coordinate, size_t max_value) {
    return coordinate >= 1 && coordinate <= max_value;
}

int read_coordinate(size_t max_value, const string &message) {
    int coordinate;

    cout << message << " ";
    cin >> coordinate;

    if (!is_valid_coordinate(coordinate, max_value)) {
        cout << "Nieprawidłowa wartość! Podaj wartość pomiędzy 1, a " << max_value << endl;

        return read_coordinate(max_value, message);
    }

    return coordinate;
}

bool is_valid_action(int action) {
    return action == SELECT_CELL_ACTION || action == FLAG_CELL_ACTION;
}

int read_action() {
    int action;

    cout << "Podaj akcje (" << SELECT_CELL_ACTION << " - klik, " << FLAG_CELL_ACTION << " - flaga): ";
    cin >> action;

    if (!is_valid_action(action)) {
        cout << "Nieprawidłowa wartość!" << endl;

        return read_action();
    }

    return action;
}

bool is_cell_clickable(BoardCell *cell) {
    if (cell->type == UNCOVERED_CELL_TYPE) return true;
    if (cell->type == UNCOVERED_BOMB_CELL_TYPE) return true;
    if (cell->type == FLAG_CELL_TYPE) return true;

    return false;
}

BoardCell *read_cell(int &x, int &y, Board board) {
    x = read_coordinate(board.board_config.columns_length, "Podaj X:") - 1;
    y = read_coordinate(board.board_config.rows_length, "Podaj Y:") - 1;

    BoardCell *selected_cell = get_board_cell(x, y, board);

    if (!is_cell_clickable(selected_cell)) {
        cout << "Nieprawidłowa komórka (" << x + 1 << ", " << y + 1 << ")!" << endl;

        return read_cell(x, y, board);
    }

    return selected_cell;
}