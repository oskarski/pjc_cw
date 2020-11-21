#include <iostream>

using namespace std;

void merge(const int *first_array, size_t first_array_size, const int *second_array, size_t second_array_size,
           int *result_array);

void printArr(const int *a, size_t dima, const char *m) {
    cout << m << " [ ";
    for (size_t i = 0; i < dima; ++i)cout << a[i] << " ";
    cout << "]\n";
}

int exercise_3() {
    int a[] = {1, 4, 4, 5, 8};
    int b[] = {1, 2, 2, 4, 6, 6, 9};
    constexpr size_t dima = size(a);
    constexpr size_t dimb = size(b);
    constexpr size_t dimc = dima + dimb;
    int c[dimc];
    merge(a, dima, b, dimb, c);
    printArr(a, dima, "a");
    printArr(b, dimb, "b");
    printArr(c, dimc, "c");

    return 0;
}

void merge(const int *first_array, size_t first_array_size, const int *second_array, size_t second_array_size,
           int *result_array) {
    int first_array_index = 0;
    int second_array_index = 0;

    for (int i = 0; i < first_array_size + second_array_size; i++) {
        if (*(first_array + first_array_index) <= *(second_array + second_array_index)) {
            *(result_array + i) = *(first_array + first_array_index++);
        } else {
            *(result_array + i) = *(second_array + second_array_index++);
        }
    }
}