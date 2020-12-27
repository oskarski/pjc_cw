bool is_valid_board_cell(size_t column_index, size_t row_index, Board board) {
    bool is_valid_column = column_index >= 0 && column_index < board.board_config.columns_length;
    bool is_valid_row = row_index >= 0 & row_index < board.board_config.rows_length;

    if (is_valid_column || is_valid_row) return true;

    return false;
}

BoardCell *get_board_cell(size_t column_index, size_t row_index, Board board) {
    if (!is_valid_board_cell(column_index, row_index, board)) return nullptr;

    size_t cell_index = (row_index * board.board_config.columns_length) + column_index;

    return board.board_cells + cell_index;
}