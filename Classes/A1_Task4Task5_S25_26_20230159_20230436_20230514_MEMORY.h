
#ifndef A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MEMORY_H
#define A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MEMORY_H

#include <bits/stdc++.h>

using namespace std;

class Memory {

private:
    const int s = 256;
    vector<string> m;
public:
    Memory();
    void clear();

    string getCell(int address);

    void setCell(int address, string val);

};


#endif //A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MEMORY_H
