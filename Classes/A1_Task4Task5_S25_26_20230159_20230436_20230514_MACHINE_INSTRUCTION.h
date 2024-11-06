#ifndef A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MACHINE_INSTRUCTION_H
#define A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MACHINE_INSTRUCTION_H

#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_REGISTER.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MEMORY.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_ALU.h"

using namespace std;

class MachineInstruction {

public:
    void Load(int idxReg, int idxMem, Register &R, Memory &M) ;

    void Load(int idxReg, const string &val, Register &R) ;

    void Store(int idxReg, int idxMem, Register &R, Memory &M) ;

    void Move(int idxReg1, int idxReg2, Register &R) ;

    void JumpB(int idxReg, int idxMem, Register &R, int &PC) ;

    void JumpD(int idxReg, int idxMem, Register &R, int &PC) ;

    bool Halt() ;

};


#endif //A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_MACHINE_INSTRUCTION_H
