#include <iostream>

using namespace std;

void render_cell(int value, int current_row);

int exercise_3() {
    int a, b, c;

    cout << "Podaj 3 nieujemne liczby całkowite: \na: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    int histogram_max_value = max(max(a, b), c);

    for (int i = histogram_max_value; i > 0; i--) {
        render_cell(a, i);
        render_cell(b, i);
        render_cell(c, i);

        cout << "\n";
    }

    return 0;
}

void render_cell(int value, int current_row) {
    if (value >= current_row) {
        cout << "*";
    } else {
        cout << " ";
    }
}