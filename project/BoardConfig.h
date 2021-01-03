#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H


class BoardConfig {
public:
    BoardConfig(int number_of_columns, int number_of_rows, int number_of_bombs);

    int get_number_of_columns();

    int get_number_of_rows();

    int get_number_of_bombs();

private:
    int number_of_columns;
    int number_of_rows;
    int number_of_bombs;
};


#endif
