
#ifndef A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_REGISTER_H
#define A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_REGISTER_H

#include <bits/stdc++.h>

using namespace std;

class Register {

private:
    const int s = 16;
    vector<string> reg;
public:
    Register();
    void clear();

    string getCell(int address);

    void setCell(int address, string val);
};

#endif //A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_REGISTER_H
