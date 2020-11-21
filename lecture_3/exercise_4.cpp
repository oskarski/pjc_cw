#include <iostream>

using namespace std;

size_t length(const char *c_string);

bool isLetter(char c);

char *reverse(char *c_string);

size_t words(const char *c_string);

size_t words2(const char *c_string);

char *concat(char *t, const char *s);

int exercise_4() {
    char s1[] = "Alice in Wonderland";
    cout << "reverse: " << reverse(s1) << endl;
    cout << "length : " << length(s1) << endl;
    char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
    cout << "words  : " << words(s2) << endl;
    cout << "words2 : " << words2(s2) << endl;
    char s3[100] = "Hello";
    cout << "concat : " << concat(concat(s3, ", world"), "!") << endl;

    return 0;
}

size_t length(const char *c_string) {
    size_t size = 0;

    while (*(c_string + size) != '\0') size++;

    return size;
}

bool isLetter(char character) {
    bool is_small_letter = character >= 97 && character <= 122;
    bool is_big_letter = character >= 65 && character <= 90;

    return is_small_letter || is_big_letter;
}

char *reverse(char *c_string) {
    size_t size = length(c_string);

    for (int i = 0; i <= size / 2; i++) {
        char tmp = *(c_string + i);
        *(c_string + i) = *(c_string + size - i - 1);
        *(c_string + size - i - 1) = tmp;
    }

    return c_string;
}

size_t words(const char *c_string) {
    size_t words = 0;
    bool wasLetter = false;

    for (int i = 0; i < length(c_string); i++) {
        bool isLetterNow = isLetter(*(c_string + i));

        if (!isLetterNow && wasLetter) words++;

        wasLetter = isLetterNow;
    }

    return words;
}

size_t words2(const char *c_string) {
    size_t words = 0;
    size_t min_word_size = 2;
    size_t word_size = 0;
    bool wasLetter = false;

    for (int i = 0; i < length(c_string); i++) {
        bool isLetterNow = isLetter(*(c_string + i));

        if (isLetterNow) word_size++;

        if (!isLetterNow && wasLetter && word_size >= min_word_size) words++;

        if (!isLetterNow) word_size = 0;

        wasLetter = isLetterNow;
    }

    return words;
}

char *concat(char *target, const char *source) {
    size_t target_size = length(target);
    size_t source_size = length(source);

    // added +1 for '\0' char
    char *tmp_target = new char[target_size + source_size + 1];

    for (int i = 0; i < target_size; i++) *(tmp_target + i) = *(target + i);
    for (int i = 0; i < source_size; i++) *(tmp_target + target_size + i) = *(source + i);

    *(tmp_target + target_size + source_size) = '\0';
    target = tmp_target;

    return target;
}