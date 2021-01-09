#include <iostream>
#include <cmath>

using namespace std;

class Point {
    double x;
    double y;
public:
    Point() {
        this->x = 0;
        this->y = 0;
    }

    Point(double coordinate) {
        this->x = coordinate;
        this->y = coordinate;
    }

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() const {
        return this->x;
    }

    double getY() const {
        return this->y;
    }

    Point &setX(double newX) {
        this->x = newX;

        return *this;
    }

    Point &setY(double newY) {
        this->y = newY;

        return *this;
    }

    Point &transX(double dx) {
        this->x += dx;

        return *this;
    }

    Point &transY(double dy) {
        this->y += dy;

        return *this;
    }

    Point &transXY(double dx, double dy) {
        this->transX(dx);
        this->transY(dy);

        return *this;
    }

    static double distance(const Point &firstPoint, const Point &secondPoint) {
        return sqrt(pow(secondPoint.x - firstPoint.x, 2) + pow(secondPoint.y - firstPoint.y, 2));
    }
};


int exercise_1() {
    Point p;
    Point q(1);
    Point r(1, 2);
    p.transXY(5, 6);
    q.transX(-1).transY(-1).transXY(2, 2);
    r.setX(10).transY(-8);
    cout << Point::distance(p, q) << endl;
    cout << Point::distance(p, r) << endl;

    return 0;
}