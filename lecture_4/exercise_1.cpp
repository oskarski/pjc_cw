#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<typename T>
int get_max_element_index(T *array, size_t length) {
    int max_index = 0;

    for (int i = 0; i < length; i++) {
        if (*(array + i) > *(array + max_index)) max_index = i;
    }

    return max_index;
}

int exercise_1() {
    int int_array[] = {1, 4, 2, 6, 3, 4, 6, -2};
    double double_array[] = {3.4, 2.4, 2.5, 2.6, 9.3, .4};
    string string_array[] = {"3.4", "2.4", "2.5", "2.6", "9.3", ".4"};

    cout << "int array max index: " << get_max_element_index(int_array, 8) << endl;
    cout << "double array max index: " << get_max_element_index(double_array, 6) << endl;
    cout << "string array max index: " << get_max_element_index(string_array, 6) << endl;

    return 0;
}