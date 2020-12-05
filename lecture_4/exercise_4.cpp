#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename PredicateFunctionType>
vector<T> filter(const vector<T> &input_vector, PredicateFunctionType predicate) {
    vector<T> output_vector = vector<T>();

    for (T vector_element : input_vector) {
        if (predicate(vector_element)) output_vector.push_back(vector_element);
    }

    return output_vector;
}

template<typename T, typename TransformFunctionType, typename PredicateFunctionType>
vector<T>
transform_and_filter(vector<T> &input_vector, TransformFunctionType transform, PredicateFunctionType predicate) {
    vector<T> output_vector = vector<T>();

    int i = 0;
    for (T vector_element : input_vector) {
        T transformed_element = transform(vector_element);

        input_vector.at(i++) = transformed_element;

        if (predicate(transformed_element)) output_vector.push_back(transformed_element);
    }

    return output_vector;
}

template<typename T>
void print_vector(const vector<T> &_vector) {
    cout << "[ ";

    for (T vector_element : _vector) {
        cout << vector_element << " ";
    }

    cout << "]" << endl;
}

int exercise_4() {
    vector<int> v{1, -3, 4, -2, 6, -8, 5};
    print_vector(v);

    vector<int> r = filter(v, [](int n) { return n % 2 == 0; });
    print_vector(r);
    vector<int> s = filter(v, [](int n) { return n > 0; });
    print_vector(s);

    vector<double> w{1.5, -3.1, 4.0, -2.0, 6.3};
    print_vector(w);
    double min = -0.5, max = 0.5;
    vector<double> d =
            transform_and_filter(w, [](double n) { return sin(n); },
                                 [min, max](double n) { return n >= min && n <= max; });
    print_vector(w);
    print_vector(d);

    return 0;
}