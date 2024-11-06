#include <bits/stdc++.h>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MACHINE.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MEMORY.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_CPU.h"
#include <QString>

using namespace std;

bool Machine::isHexadecimal(string &line) {
    for (size_t i = 0; i < line.length(); ++i) {
        line[i] = toupper(line[i]);
        QChar ch = line[i];
        if (!ch.isDigit() && (ch < 'A' || ch > 'F'))
            return false;
    }
    return true;
}


bool Machine::LoadProgrameFile(string fname) {
    ifstream f(fname);
    string line;
    if (f.is_open()) {
        while (getline(f, line)) {
            if (line.length() != 4 or !isHexadecimal(line)) return false;
            M.setCell(cnt, string(1, line[0]) + line[1]);
            cnt++;
            M.setCell(cnt, string(1, line[2]) + line[3]);
            cnt++;
        }
        f.close();
        return true;
    } else
        return false;
}

bool Machine::StoreOperation(string &line) {
    if (line.length() != 4 or !isHexadecimal(line)) return false;
    M.setCell(cnt, string(1, line[0]) + line[1]);
    cnt++;
    M.setCell(cnt, string(1, line[2]) + line[3]);
    cnt++;
    return true;
}

void Machine::operate() {
    cpu.runTillHalt(M);
}

void Machine::nextStep() {
    cpu.runNextStep(M);
}

Memory Machine::MainMemory() {
    return M;
}

CPU* Machine::MainCPU() {
    return &cpu;
}

int Machine::GetLastCell() {
    return cnt;
}

void Machine::SetCnt(int n) {
    cnt = n;
}

