#include <iostream>

using namespace std;

#include "BoardConfig.h"
#include "InputReader.h"
#include "Board.h"

int main() {
    bool is_game_finished = false;
    BoardConfig *difficulty_levels[] = {
            new BoardConfig(5, 5, 5),
            new BoardConfig(7, 7, 12),
            new BoardConfig(10, 10, 30)
    };

    int difficulty_level_index = InputReader::read_difficulty_level() - 1;

    BoardConfig *board_config = difficulty_levels[difficulty_level_index];
    Board *board = new Board(board_config);

    board->render();

    while (!is_game_finished) {
        int column = InputReader::read_column(board_config) - 1;
        int row = InputReader::read_row(board_config) - 1;

        if (!board->is_cell_clickable(column, row)) {
            cout << "Nieprawidłowe pole!" << endl;
            continue;
        }

        BoardAction action = InputReader::read_action();

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