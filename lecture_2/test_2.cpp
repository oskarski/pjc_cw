#include <iostream>

using namespace std;

int *func(int tab[], int size);

int main() {
    int tab[] = {1, 3, 9, 2, 5};

    cout << func(tab, 5) << "\n";

    return 0;
}

int *func(int tab[], int size) {
    int *max_pointer;

    for (int i = 0; i < size; i++) {
        if (tab[i] > *max_pointer) {
            max_pointer = &tab[i];
        }
    }

    return max_pointer;
}
