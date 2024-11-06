

#ifndef A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_CPU_H
#define A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_CPU_H


#include <bits/stdc++.h>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MEMORY.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MACHINE_INSTRUCTION.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_REGISTER.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_ALU.h"

using namespace std;

class CPU {
private:
    enum class oPcode{
        LOAD_1,
        LOAD_2,
        STORE_3,
        MOVE_4,
        ADD_5,
        ADD_6,
        OR_7,
        AND_8,
        XOR_9,
        ROTATE_A,
        JUMP_B,
        HALT_C,
        JUMP_D
    };
    oPcode instruction;
    int pc = 10;
    MachineInstruction MI;
    Register R;
    ALU alu;
    string instructionRegister;

    string Fetch(Memory& M);

    vector<int> Decode(Memory& M) ;

    void Execute(Memory& M) ;

public:
    void runTillHalt(Memory& M) ;
    void runNextStep(Memory& M);
    Register MainRegister();
    int programCounter();
    void setProgramCounter(int n);
    bool IsHalted();
};

#endif //A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_CPU_H
