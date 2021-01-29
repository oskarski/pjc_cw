#include <iostream>
#include <fstream>

using namespace std;

#include "ScoreRepository.h"

void ScoreRepository::save_score(int score, const char *name) {
    fstream file;
    file.open("scores.txt", fstream::app);

    if (file.is_open()) {
        file << name << " " << score << "\n";
        file.close();
    }
}

void ScoreRepository::read_scores() {

}
