#include <iostream>

using namespace std;

double bmi(double weight, double height);

int exercise_1() {
    double height = 0, weight = 0;

    cout << "Podaj wzrost w metrach: ";
    cin >> height;

    cout << "Podaj wagę w kilogramach: ";
    cin >> weight;

    cout << "Twoje BMI: " << bmi(weight, height);

    return 1;
}

double bmi(double weight, double height) {
    return weight / (height * height);
}