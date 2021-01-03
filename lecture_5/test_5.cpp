#include "iostream"

using namespace std;

struct RGB {
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

int main() {
    RGB first_color{0, 0, 0};
    RGB second_color{255, 255, 255};
    RGB average_color{
            (first_color.r + second_color.r) / 2,
            (first_color.g + second_color.g) / 2,
            (first_color.b + second_color.b) / 2
    };

    cout << "First: (" << first_color.r << ", " << first_color.g << ", " << first_color.b << ")" << endl;
    cout << "Second: (" << second_color.r << ", " << second_color.g << ", " << second_color.b << ")" << endl;
    cout << "Average: (" << average_color.r << ", " << average_color.g << ", " << average_color.b << ")" << endl;

    return 0;
}
