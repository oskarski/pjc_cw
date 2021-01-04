#include <iostream>

using namespace std;

#include "BoardConfig.h"
#include "InputReader.h"
#include "Board.h"

int main() {
    bool is_game_finished = false;

    BoardConfig *board_config = new BoardConfig(6, 6, 6);
    Board *board = new Board(board_config);
    InputReader *input_reader = new InputReader(board_config);

    board->render();

    while (!is_game_finished) {
        int column = input_reader->read_column() - 1;
        int row = input_reader->read_row() - 1;

        if (!board->is_cell_clickable(column, row)) {
            cout << "Nieprawidłowe pole!" << endl;
            continue;
        }

        BoardAction action = input_reader->read_action();

        if (action == BoardAction::QUIT_ACTION) break;
        if (action == BoardAction::FLAG_ACTION) board->toggle_flag(column, row);
        if (action == BoardAction::SELECT_ACTION) is_game_finished = board->select_cell(column, row);

        board->render();

        if (is_game_finished) {
            cout << "Przegrana!" << endl;
        }

        if (board->is_game_won()) {
            cout << "Wygrana!" << endl;
            is_game_finished = true;
        }
    }

    return 0;
}