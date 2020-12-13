#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Rectangle {
    Point top_left_corner;
    Point bottom_right_corner;
};

vector<double> process(const Rectangle *rectangle_array, size_t size, function<double(Rectangle)> func);

int exercise_1() {
    Rectangle rectangle_array[] = {
            {Point{0, 4},  Point{4, 1}},
            {Point{-6, 3}, Point{6, -2}},
            {Point{-7, 4}, Point{8, -4}}
    };

    vector areas_vector = process(rectangle_array, 3, [](Rectangle rectangle) {
        double y = abs(rectangle.top_left_corner.y - rectangle.bottom_right_corner.y);
        double x = abs(rectangle.top_left_corner.x - rectangle.bottom_right_corner.x);

        return x * y;
    });

    vector diagonals_vector = process(rectangle_array, 3, [](Rectangle rectangle) {
        double y = abs(rectangle.top_left_corner.y - rectangle.bottom_right_corner.y);
        double x = abs(rectangle.top_left_corner.x - rectangle.bottom_right_corner.x);

        return sqrt(x*x + y*y);
    });

    cout << "Areas: " << endl;

    for (double area : areas_vector) {
        cout << area << endl;
    }

    cout << "Diagonals: " << endl;

    for (double area : diagonals_vector) {
        cout << area << endl;
    }

    return 0;
}

vector<double> process(const Rectangle *rectangle_array, size_t size, function<double(Rectangle)> func) {
    vector<double> output_vector = vector<double>(size);

    for (int i = 0; i < size; i++) {
        output_vector[i] = func(*(rectangle_array + i));
    }

    return output_vector;
}