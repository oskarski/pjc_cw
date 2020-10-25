#include <iostream>

using namespace std;

int exercise_3() {
    int input;
    int prev_input = 0;
    int same_input_counter = 1;

    int highest_same_input = 0;
    int highest_same_input_counter = 0;

    do {
        cout << "Podaj liczbe calkowita (0 aby zakonczyc): ";
        cin >> input;

        if (prev_input == input) same_input_counter++;

        if (prev_input != input) {
            if (same_input_counter > highest_same_input_counter) {
                highest_same_input_counter = same_input_counter;
                highest_same_input = prev_input;
            }

            same_input_counter = 1;
        }

        prev_input = input;
    } while (input != 0);

    cout << "Longest sequence: " << highest_same_input << " times " << highest_same_input_counter;

    return 0;
}