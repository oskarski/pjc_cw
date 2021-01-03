#ifndef INPUT_READER_H
#define INPUT_READER_H

#include "BoardConfig.h"
#include "BoardAction.h"

class InputReader {
private:
    BoardConfig *board_config;

public:
    InputReader(BoardConfig *board_config);

    int read_column();

    int read_row();

    BoardAction read_action();

private:
    bool is_valid_column(int column);

    bool is_valid_row(int row);

    static bool is_valid_action(int action);
};


#endif
