#include <iostream>
#include <cmath>

using namespace std;

void quadratic_function_resolver(double a, double b, double c);

int exercise_2() {
    double a = 0, b = 0, c = 0;

    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << "Podaj c: ";
    cin >> c;

    quadratic_function_resolver(a, b, c);

    return 0;
}

void quadratic_function_resolver(double a, double b, double c) {
    double d = (b * b) - (4 * a * c);

    if (d < 0 || a == 0) {
        cout << "Nie ma pierwiastków rzeczywistych";
    } else if (d == 0) {
        cout << "x0 = " << -0.5 * b / a;
    } else {
        double d_sqrt = sqrt(d);
        double x1 = ((-1) * b - d_sqrt) / (2 * a);
        double x2 = ((-1) * b + d_sqrt) / (2 * a);

        cout << "x1 = " << x1 << ", x2 = " << x2;
    }
}