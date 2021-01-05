#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "BoardConfig.h"
#include "BoardAction.h"

class InputReader {
public:
    static int read_difficulty_level();

    static int read_column(BoardConfig *board_config);

    static int read_row(BoardConfig *board_config);

    static BoardAction read_action();

private:
    static bool is_valid_column(int column, BoardConfig *board_config);

    static bool is_valid_row(int row, BoardConfig *board_config);

    static bool is_valid_action(int action);
};


#endif
