#ifndef SCOREREPOSITORY_H
#define SCOREREPOSITORY_H

class ScoreRepository {
public:
    static void save_score(int score, const char *name);

    static void print_scores();
};

#endif
