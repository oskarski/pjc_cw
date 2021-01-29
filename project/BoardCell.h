#ifndef BOARD_CELL_H
#define BOARD_CELL_H

#include <iostream>

using namespace std;

class BoardCell {
private:
    bool is_bomb;
    bool is_flagged;
    int value;

    const static int UNCOVERED_VALUE = -1;
    const static int DETONATED_VALUE = -2;

public:
    static BoardCell *create();

    static BoardCell *create_as_bomb();

    void render() const;

    void uncover(int number_of_nearby_bombs);

    void toggle_flag();

    bool is_clickable() const;

    bool contains_bomb() const;

    bool contains_flag() const;

    bool is_in_win_state() const;

    void detonate();

private:
    BoardCell(bool is_bomb);
};


#endif
