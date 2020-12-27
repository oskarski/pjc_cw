#include <iostream>

using namespace std;

enum Banks {
    PKO, BGZ, BRE, BPH
};

struct Account {
    Banks bank;
    int balance;
};

struct Person {
    char name[20];
    Account account;
};

struct Couple {
    Person he;
    Person she;
};

const Couple *bestClient(const Couple *couples, int size, Banks bank);

int exercise_2() {
    Couple couples[] = {
            {Person{"Johny", Account{PKO, 1200}}, Person{"Mary", Account{BGZ, 1400}}},
            {Person{"Peter", Account{BGZ, 1400}}, Person{"Suzy", Account{BRE, -1500}}},
            {Person{"Kevin", Account{PKO, 1600}}, Person{"Katy", Account{BPH, 1500}}},
            {Person{"Kenny", Account{BPH, 200}},  Person{"Lucy", Account{BRE, -201}}},
    };

    const Couple* p = bestClient(couples, 4, BRE);

    if (p) {
        cout << p->he.name << " and " << p->she.name
             << ": " << p->he.account.balance +
                        p->she.account.balance << endl;
    } else {
        cout << "No such couple...\n";
    }

    return 0;
}

const Couple *bestClient(const Couple *couples, int size, Banks bank) {
    const Couple *highest_savings_couple = nullptr;

    for (int i = 0; i < size; i++) {
        const Couple *couple = (couples + i);

        if (couple->he.account.bank == bank || couple->she.account.bank == bank) {
            if (highest_savings_couple == nullptr) highest_savings_couple = couple;

            int couple_total = couple->he.account.balance + couple->she.account.balance;
            int highest_savings_couple_total = highest_savings_couple->he.account.balance + highest_savings_couple->she.account.balance;

            if (couple_total > highest_savings_couple_total) highest_savings_couple = couple;
        }
    }

    return highest_savings_couple;
}