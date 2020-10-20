#include <iostream>

int guess_number(int min, int max);

int exercise_5() {
    int min = 1, max = 1000000;

    cout << "Pomysk liczbe od " << min << " do " << max << "\n";

    int questions_number = guess_number(min, max) + 1;
    cout << "Udało się odgaść po " << questions_number << " pytaniach.";


    return 0;
}

int guess_number(int min, int max) {
    int guess = (max - min) / 2 + min;
    char answer;
    char small = 's';
    char big = 'b';
    char yes = 'y';

    cout << "Czy to " << guess << "? (" << small << "," << big << "," << yes << "): ";
    cin >> answer;

    switch (answer) {
        case 's':
            return guess_number(guess, max) + 1;
        case 'b':
            return guess_number(min, guess) + 1;
        case 'y':
            cout << "Pomyślana liczba to: " << guess;
            return 0;
        default:
            cout << "Podano nie poprawną odpowiedź. Dostępne opcje (" << small << "," << big << "," << yes << ")";
            return guess_number(min, max);
    }
}