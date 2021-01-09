#include <iostream>
#include <cmath>

using namespace std;

class Rect {
private:
    double a;
    double b;
public:
    Rect() {
        this->a = 1;
        this->b = 1;
    }

    Rect(double size) {
        this->a = size;
        this->b = size;
    }

    Rect(double a, double b) {
        this->a = a;
        this->b = b;
    }

    double getA() const {
        return this->a;
    }

    double getB() const {
        return this->b;
    }

    double getDiagonal() const {
        return sqrt(pow(this->a, 2) + pow(this->b, 2));
    }

    double getArea() const {
        return this->a * this->b;
    }

    bool isLargerThan(const Rect &rectangle) {
        return this->getArea() > rectangle.getArea();
    }

    void info() {
        cout << "Rect[" << this->a << ", " << this->b << "]";
    }
};

int exercise_2() {
    Rect r1;
    Rect r2(2);
    Rect r3(3, 4);

    cout << "Rect()" << endl;
    cout << "a = " << r1.getA() << ", b = " << r1.getB() << endl;
    cout << "diagonal = " << r1.getDiagonal() << endl;
    cout << "area = " << r1.getArea() << endl;
    cout << (r1.isLargerThan(r2) ? "r1 > r2" : "r1 < r2") << endl;
    cout << (r1.isLargerThan(r3) ? "r1 > r3" : "r1 < r3") << endl;
    r1.info();
    cout << endl;
    cout << endl;

    cout << "Rect(2)" << endl;
    cout << "a = " << r2.getA() << ", b = " << r2.getB() << endl;
    cout << "diagonal = " << r2.getDiagonal() << endl;
    cout << "area = " << r2.getArea() << endl;
    cout << (r2.isLargerThan(r1) ? "r2 > r1" : "r2 < r1") << endl;
    cout << (r2.isLargerThan(r3) ? "r2 > r3" : "r2 < r3") << endl;
    r2.info();
    cout << endl;
    cout << endl;

    cout << "Rect(3, 4)" << endl;
    cout << "a = " << r3.getA() << ", b = " << r3.getB() << endl;
    cout << "diagonal = " << r3.getDiagonal() << endl;
    cout << "area = " << r3.getArea() << endl;
    cout << (r3.isLargerThan(r1) ? "r3 > r1" : "r3 < r1") << endl;
    cout << (r3.isLargerThan(r2) ? "r3 > r2" : "r3 < r2") << endl;
    r3.info();
    cout << endl;
    cout << endl;

    return 0;
}