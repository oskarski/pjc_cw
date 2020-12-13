#include "iostream"
#include "vector"

using namespace std;

template<typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
vector<T> sort(vector<T> input_vector) {
    int min_value_index;

    for (int i = 0; i < input_vector.size() - 1; i++) {
        min_value_index = i;

        for (int j = i + 1; j < input_vector.size(); j++) {
            if (input_vector[j] < input_vector[min_value_index]) min_value_index = j;
        }

        swap(&input_vector[min_value_index], &input_vector[i]);
    }

    return input_vector;
}

int main() {
    vector<int> int_vector{5, 3, 5, -2, -1, 6, 2, -7};
    vector<double> double_vector{5.1, 3.2, 5.4, -2.2, -1.1, 6, 2, -7};

    for (int vector_element : sort(int_vector)) {
        cout << vector_element << " ";
    }

    cout << endl;

    for (double vector_element : sort(double_vector)) {
        cout << vector_element << " ";
    }

    return 0;
}
