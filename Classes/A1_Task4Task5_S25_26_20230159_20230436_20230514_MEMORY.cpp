#include <bits/stdc++.h>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MEMORY.h"

using namespace std;

Memory::Memory() : m(s, "00") {}

void Memory::clear() {
    for (int i = 0; i < 256; i++) {
        m[i] = "00";
    }
}

string Memory::getCell(int address) {
    return m[address];
}

void Memory::setCell(int address, string val) {
    m[address] = val;
}

