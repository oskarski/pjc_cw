#include <iostream>

using namespace std;

void render_empty_line(int times = 1) {
    for (int i = 0; i < times; i++) cout << endl;
}

void render_board_cell(BoardCell *board_cell) {
    switch (board_cell->type) {
        case UNCOVERED_CELL_TYPE:
        case UNCOVERED_BOMB_CELL_TYPE:
            cout << "⬜️";
            break;
        case BOMB_CELL_TYPE:
            cout << "💣";
            break;
        case FLAG_CELL_TYPE:
        case UNCOVERED_FLAGGED_BOMB_CELL_TYPE:
            cout << "🚩";
            break;
        case 0:
            cout << "⏹";
            break;
        case 1:
            cout << "1️⃣";
            break;
        case 2:
            cout << "2️⃣";
            break;
        case 3:
            cout << "3️⃣";
            break;
        case 4:
            cout << "4️⃣";
            break;
        case 5:
            cout << "5️⃣";
            break;
        case 6:
            cout << "6️⃣";
            break;
        case 7:
            cout << "7️⃣";
            break;
        case 8:
            cout << "8️⃣";
            break;
        case 9:
            cout << "9️⃣";
            break;
    }
}

void render_board(Board board) {
    for (int row = 0; row < board.board_config.rows_length; row++) {
        for (int column = 0; column < board.board_config.columns_length; column++) {
            render_board_cell(get_board_cell(column, row, board));
        }
        render_empty_line();
    }

    render_empty_line();
}