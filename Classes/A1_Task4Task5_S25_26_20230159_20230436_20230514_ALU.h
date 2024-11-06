
#ifndef A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_ALU_H
#define A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_ALU_H


#include<iostream>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_REGISTER.h"

using namespace std;

class ALU {
private:
    string hexToBinary(const string &hex);

    string binaryToHex(const string &binary);
    string addBinary(const string &bin1, const string &bin2) ;

public:
    static string hex_to_dec(const string &hexStr) ;


    static string dec_to_hex(const string& decimalValue);

    void Rotate(int idxReg, Register &R, int shift);

    void addfloat(int idx1, int idx2, int idx3, Register &reg) ;

    void add(int idx1, int idx2, int idx3, Register &reg);

    void AND(int idxReg1, int idxReg2, int idxReg3, Register &R);

    void OR(int idxReg1, int idxReg2, int idxReg3, Register &R);

    void XOR(int idxReg1, int idxReg2, int idxReg3, Register &R);

};

#endif //A1_TASK4TASK5_S25_26_20230159_20230436_20230514_A1_TASK4TASK5_S25_26_20230159_20230436_20230514_ALU_H
