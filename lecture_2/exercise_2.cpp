#include <iostream>
#include <cmath>

using namespace std;

const double *aver(const double *arr, size_t size, double &average);

int exercise_2() {
    double arr[] = {1, 7, 5, 4, 3, 2};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    double average = 0;

    const double *p = aver(arr, size, average);

    cout << *p << " " << average << endl;

    return 0;
}

const double *aver(const double *arr, size_t size, double &average) {
    for (int i = 0; i < size; i++) average += arr[i];

    average = average / size;

    const double *closest_to_avg = arr;

    for (int i = 0; i < size; i++) {
        double difference = abs(arr[i] - average);
        double last_difference = abs(*closest_to_avg - average);

        if (difference < last_difference) closest_to_avg = &arr[i];
    }

    return closest_to_avg;
}
