#include <iostream>

#define POL

#if defined(POL) && defined(ENG)
#error "Both POL and ENG can not be deinfed!"
#endif

#if (!defined(POL) && !defined(ENG))
#error "Either POL or ENG must be defined!"
#endif

int read_number();
int sum_digits(int number);
void print_result(int number, int digits_sum);

int exercise_4() {
    int number = 1;
    int highest_number = 0;
    int highest_sum = 0;

    while (number != 0) {
        number = read_number();
        int sum = sum_digits(number);

        if (sum > highest_sum) {
            highest_sum = sum;
            highest_number = number;
        }
    }

    print_result(highest_number, highest_sum);

    return 0;
}

int read_number() {
#ifdef POL
    cout << "podaj liczbe naturalna (0 aby zakonczyc): ";
#endif
#ifdef ENG
    cout << "enter a natural number (0 if done): ";
#endif
    int n;
    cin >> n;
    return n;
}

int sum_digits(int number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

void print_result(int number, int digits_sum) {
#ifdef POL
    cout << "Najwieksza suma cyfr to " << digits_sum << " dla " << number;
#endif
#ifdef ENG
    cout << "Max sum of digits was " << digits_sum << " for " << number;
#endif
}