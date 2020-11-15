#include <iostream>

using namespace std;


void ord3(double &a, double &b, double &c);

void ord3(double *a, double *b, double *c);

void getMinMax(const double &a, const double &b, const double &c, const double *&pMin, const double *&pMax);

void getMinMax(const double *a, const double *b, const double *c, const double **pMin, const double **pMax);


void printOrd(const double *a, const double *b, const double *c) {
    cout << *a << " " << *b << " " << *c << endl;
}

void printMinMax(const double *pmn, const double *pmx) {
    cout << "Min = " << *pmn << "; " << "Max = " << *pmx << endl;
}

void swap(double &a, double &b);

int exercise_2() {
    double a, b, c;
    const double *pMin, *pMax;

    a = 2;
    b = 1;
    c = 3;

    ord3(a, b, c);
    printOrd(&a, &b, &c);

    a = 3;
    b = 2;
    c = 1;
    ord3(&a, &b, &c);
    printOrd(&a, &b, &c);

    a = -1;
    b = -1;
    c = 1;
    ord3(&a, &b, &c);
    printOrd(&a, &b, &c);

    a = 2;
    b = 3;
    c = 1;
    getMinMax(a, b, c, pMin, pMax);
    printMinMax(pMin, pMax);

    a = 3;
    b = 1;
    c = 2;
    getMinMax(&a, &b, &c, &pMin, &pMax);
    printMinMax(pMin, pMax);

    a = 3;
    b = 3;
    c = -1;
    getMinMax(&a, &b, &c, &pMin, &pMax);
    printMinMax(pMin, pMax);

    return 0;
}

void swap(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}

void ord3(double &a, double &b, double &c) {
    // a b c
    if (a <= b && b <= c) return;
    // b a c
    if (b <= a && a <= c) {
        swap(a, b);
        return;
    }
    // a c b
    if (a <= c && c <= b) {
        swap(b, c);
        return;
    }
    // b c a
    if (b <= c && c <= a) {
        swap(a, b);
        swap(b, c);
        return;
    }
    // c a b
    if (c <= a && a <= b) {
        swap(a, c);
        swap(b, c);
        return;
    }
    // c b a
    if (c <= b && b <= a) {
        swap(a, c);
        return;
    }
}

void ord3(double *a, double *b, double *c) {
    // a b c
    if (*a <= *b && *b <= *c) return;
    // b a c
    if (*b <= *a && *a <= *c) {
        swap(*a, *b);
        return;
    }
    // a c b
    if (*a <= *c && *c <= *b) {
        swap(*b, *c);
        return;
    }
    // b c a
    if (*b <= *c && *c <= *a) {
        swap(*a, *b);
        swap(*b, *c);
        return;
    }
    // c a b
    if (*c <= *a && *a <= *b) {
        swap(*a, *c);
        swap(*b, *c);
        return;
    }
    // c b a
    if (*c <= *b && *b <= *a) {
        swap(*a, *c);
        return;
    }
}

void getMinMax(const double &a, const double &b, const double &c, const double *&pMin, const double *&pMax) {
    if (a >= b && a >= c) pMax = &a;
    if (b >= a && b >= c) pMax = &b;
    if (c >= a && c >= b) pMax = &c;

    if (a <= b && a <= c) pMin = &a;
    if (b <= a && b <= c) pMin = &b;
    if (c <= a && c <= b) pMin = &c;
}

void getMinMax(const double *a, const double *b, const double *c, const double **pMin, const double **pMax) {
    if (*a >= *b && *a >= *c) *pMax = a;
    if (*b >= *a && *b >= *c) *pMax = b;
    if (*c >= *a && *c >= *b) *pMax = c;

    if (*a <= *b && *a <= *c) *pMin = a;
    if (*b <= *a && *b <= *c) *pMin = b;
    if (*c <= *a && *c <= *b) *pMin = c;
}