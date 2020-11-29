#include <iostream>
#include <string>

using namespace std;

template<typename T>
T getMaxRecur(const T *array, size_t length) {
    if (length == 1) return *array;

    T prevValue = getMaxRecur(array, length - 1);
    T currentValue = *(array + length - 1);

    if (currentValue > prevValue) return currentValue;

    return prevValue;
}

int exercise_2() {
    double ad[]{2.5, 9.1, 4.5, -1.0};
    cout << "ad: " << getMaxRecur(ad, 4) << "; ";

    int ai[]{2, 11, 5, 1, 9};
    cout << "ai: " << getMaxRecur(ai, 5) << "; ";

    string as[]{"Ala", "Ela", "Ula", "Ola"};
    cout << "as: " << getMaxRecur(as, 4) << endl;


    return 0;
}