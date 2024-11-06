
#ifndef A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MACHINE_H
#define A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MACHINE_H

#include <bits/stdc++.h>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MEMORY.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_CPU.h"
#include <QString>
using namespace std;

class Machine
{
private:
    CPU cpu;
    Memory M;
    int cnt = 10;

    bool isHexadecimal(string& line);

public:
    bool LoadProgrameFile(string fname);
    bool StoreOperation(string& line);
    void operate();
    void nextStep();
    Memory MainMemory();

    CPU* MainCPU();

    int GetLastCell();

    void SetCnt(int n);
};



#endif //A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MACHINE_H
