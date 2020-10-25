#include <iostream>

using namespace std;

void minMaxRep(int arr[], size_t size, int &min, size_t &min_counter, int &max, size_t &max_counter);

int exercise_1() {
    int arr[]{2, 3, 4, 2, 7, 4, 7, 2};
    int mn, mx;
    size_t in, ix;
    size_t size = sizeof(arr) / sizeof(*arr);

    minMaxRep(arr, size, mn, in, mx, ix);

    cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "]\n";
    cout << "Min = " << mn << " " << in << " times\n";
    cout << "Max = " << mx << " " << ix << " times\n";

    return 0;
}

void minMaxRep(int arr[], size_t size, int &min, size_t &min_counter, int &max, size_t &max_counter) {
    if (size > 0) min = max = arr[0];

    min_counter = 0;
    max_counter = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_counter = 0;
        }

        if (arr[i] < min) {
            min = arr[i];
            min_counter = 0;
        }

        if (arr[i] == max) max_counter++;
        if (arr[i] == min) min_counter++;
    }
}