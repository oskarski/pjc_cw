#include "BoardCell.h"

BoardCell *BoardCell::create() {
    return new BoardCell(false);
}

BoardCell *BoardCell::create_as_bomb() {
    return new BoardCell(true);
}

BoardCell::BoardCell(bool is_bomb) {
    this->is_flagged = false;
    this->value = BoardCell::UNCOVERED_VALUE;
    this->is_bomb = is_bomb;
}

void BoardCell::render() const {
    string numbered_cells[] = {"⏹", "1️⃣", "2️⃣", "3️⃣", "4️⃣", "5️⃣", "6️⃣", "7️⃣", "8️⃣", "9️⃣"};

    if (this->is_bomb && this->value != BoardCell::UNCOVERED_VALUE) {
        cout << "💣";
        return;
    }

    if (this->is_flagged) {
        cout << "🚩";
        return;
    }

    if (this->value >= 0 && this->value <= 9) {
        cout << numbered_cells[this->value];
        return;
    }

    cout << "⬜️";
}

void BoardCell::uncover(int number_of_nearby_bombs) {
    this->value = number_of_nearby_bombs;
}

void BoardCell::toggle_flag() {
    this->is_flagged = !this->is_flagged;
}

bool BoardCell::is_clickable() const {
    return this->value == BoardCell::UNCOVERED_VALUE;
}

bool BoardCell::contains_bomb() const {
    return this->is_bomb;
}

void BoardCell::detonate() {
    if (this->contains_bomb()) this->value = BoardCell::DETONATED_VALUE;
}

bool BoardCell::is_in_win_state() const {
    if (this->is_bomb) return this->is_flagged;

    return !this->is_flagged && this->value > BoardCell::UNCOVERED_VALUE;
}
