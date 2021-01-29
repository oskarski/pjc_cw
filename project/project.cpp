#include <iostream>

using namespace std;

#include "BoardConfig.h"
#include "InputReader.h"
#include "Board.h"

int main() {
    bool is_game_finished = false;
    BoardConfig *difficulty_levels[] = {
            new BoardConfig(5, 5, 5, 3),
            new BoardConfig(7, 7, 12, 2),
            new BoardConfig(10, 10, 30, 1)
    };

    int difficulty_level_index = InputReader::read_difficulty_level() - 1;

    BoardConfig *board_config = difficulty_levels[difficulty_level_index];
    Board *board = new Board(board_config);
    int left_number_of_hints = board_config->get_number_of_hints();
    int column;
    int row;

    board->render();

    while (!is_game_finished) {
        BoardAction action = InputReader::read_action();

        if (action == BoardAction::HINT_ACTION) {
            if (left_number_of_hints < 0) {
                cout << "Nie masz juz podpowiedzi!" << endl;
                continue;
            }

            board->flag_nearest_bomb(column, row);
            left_number_of_hints--;
        } else {
            column = InputReader::read_column(board_config) - 1;
            row = InputReader::read_row(board_config) - 1;

            if (!board->is_cell_clickable(column, row)) {
                cout << "Nieprawidłowe pole!" << endl;
                continue;
            }

            if (action == BoardAction::QUIT_ACTION) break;
            if (action == BoardAction::FLAG_ACTION) board->toggle_flag(column, row);
            if (action == BoardAction::SELECT_ACTION) is_game_finished = board->select_cell(column, row);
        }

        cout << "Podpowiedzi: " << left_number_of_hints << endl;

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