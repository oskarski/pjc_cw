#include <iostream>

using namespace std;

double abs(double n);

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3);

int main() {
    double x1, y1, x2, y2, x3, y3;

    cout << "Podaj x1:";
    cin >> x1;
    cout << "Podaj y1:";
    cin >> y1;
    cout << "Podaj x2:";
    cin >> x2;
    cout << "Podaj y2:";
    cin >> y2;
    cout << "Podaj x3:";
    cin >> x3;
    cout << "Podaj y3:";
    cin >> y3;

    double area = triangle_area(x1, y1, x2, y2, x3, y3);

    cout << "Pole trojkata = " << area;

    return 0;
}

double abs(double n) {
    if (n >= 0) return n;

    return 0 - n;
}

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}