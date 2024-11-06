#include <bits/stdc++.h>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_REGISTER.h"

using namespace std;

Register::Register() : reg(s, "00") {}

void Register::clear() {
    for (auto &i: reg) {
        i = "00";
    }
}

string Register::getCell(int address) {
    return reg[address];
}

void Register::setCell(int address, string val) {
    reg[address] = val;
}
