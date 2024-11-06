#include <bits/stdc++.h>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_CPU.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MEMORY.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MACHINE_INSTRUCTION.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_REGISTER.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_ALU.h"

using namespace std;


string CPU::Fetch(Memory &M) {
    string inst = M.getCell(pc) + M.getCell(pc + 1);
    pc += 2;
    return inst;
}

vector<int> CPU::Decode(Memory &M) {
    string inst = Fetch(M);
    vector<int> code;
    char op = inst[0];
    map<char, int> decode = {
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9},
            {'A', 10},
            {'B', 11},
            {'C', 12},
            {'D', 13},
            {'E', 14},
            {'F', 15}
    };
    code.push_back(decode[op]);
    switch (op) {
        case '1':
            instruction = oPcode::LOAD_1;
            code.push_back(decode[inst[1]]);
            code.push_back(stoi(ALU::hex_to_dec(inst.substr(2))));
            break;
        case '2':
            instruction = oPcode::LOAD_2;
            code.push_back(decode[inst[1]]);
            code.push_back(stoi(ALU::hex_to_dec(inst.substr(2))));
            break;
        case '3':
            instruction = oPcode::STORE_3;
            code.push_back(decode[inst[1]]);
            code.push_back(stoi(ALU::hex_to_dec(inst.substr(2))));
            break;
        case '4':
            instruction = oPcode::MOVE_4;
            code.push_back(decode[inst[2]]);
            code.push_back(decode[inst[3]]);
            break;
        case '5':
            instruction = oPcode::ADD_5;
            code.push_back(decode[inst[1]]);
            code.push_back(decode[inst[2]]);
            code.push_back(decode[inst[3]]);
            break;
        case '6':
            instruction = oPcode::ADD_6;
            code.push_back(decode[inst[1]]);
            code.push_back(decode[inst[2]]);
            code.push_back(decode[inst[3]]);
            break;
        case '7':
            instruction = oPcode::OR_7;
            code.push_back(decode[inst[1]]);
            code.push_back(decode[inst[2]]);
            code.push_back(decode[inst[3]]);
            break;
        case '8':
            instruction = oPcode::AND_8;
            code.push_back(decode[inst[1]]);
            code.push_back(decode[inst[2]]);
            code.push_back(decode[inst[3]]);
            break;
        case '9':
            instruction = oPcode::XOR_9;
            code.push_back(decode[inst[1]]);
            code.push_back(decode[inst[2]]);
            code.push_back(decode[inst[3]]);
            break;
        case 'A':
            instruction = oPcode::ROTATE_A;
            code.push_back(decode[inst[1]]);
            code.push_back(decode[inst[3]]);
            break;
        case 'B':
            instruction = oPcode::JUMP_B;
            code.push_back(decode[inst[1]]);
            code.push_back(stoi(ALU::hex_to_dec(inst.substr(2))));
            break;
        case 'C':
            instruction = oPcode::HALT_C;
            code.push_back(decode[inst[1]]);
            code.push_back(decode[inst[2]]);
            code.push_back(decode[inst[3]]);
            break;
        case 'D':
            instruction = oPcode::JUMP_D;
            code.push_back(decode[inst[1]]);
            code.push_back(stoi(ALU::hex_to_dec(inst.substr(2))));
            break;

    }
    return code;
}

void CPU::Execute(Memory &M) {
    vector<int> code = Decode(M);
    switch (instruction) {
        case oPcode::LOAD_1:
            MI.Load(code[1], code[2], R, M);
            break;
        case oPcode::LOAD_2:
            MI.Load(code[1], ALU::dec_to_hex(to_string(code[2])), R);
            break;
        case oPcode::STORE_3:
            MI.Store(code[1], code[2], R, M);
            break;
        case oPcode::MOVE_4:
            MI.Move(code[1], code[2], R);
            break;
        case oPcode::ADD_5:
            alu.add(code[1], code[2], code[3], R);
            break;
        case oPcode::ADD_6:
            alu.addfloat(code[1], code[2], code[3], R);
            break;
        case oPcode::OR_7:
            alu.OR(code[1], code[2], code[3], R);
            break;
        case oPcode::AND_8:
            alu.AND(code[1], code[2], code[3], R);
            break;
        case oPcode::XOR_9:
            alu.XOR(code[1], code[2], code[3], R);
            break;
        case oPcode::ROTATE_A:
            alu.Rotate(code[1], R, code[2]);
            break;
        case oPcode::JUMP_B:
            MI.JumpB(code[1], code[2], R, pc);
            break;
        case oPcode::HALT_C:
            MI.Halt();
            break;
        case oPcode::JUMP_D:
            MI.JumpD(code[1], code[2], R, pc);
            break;
    }

}

void CPU::runTillHalt(Memory &M) {
    while (instruction != oPcode::HALT_C && pc < 256) {
        Execute(M);
    }
}

void CPU::runNextStep(Memory &M) {
    Execute(M);
}

Register CPU::MainRegister() {
    return R;
}

int CPU::programCounter() {
    return pc;
}

void CPU::setProgramCounter(int n) {
    pc = n;
}

bool CPU::IsHalted() {
    if (instruction == oPcode::HALT_C)
        return true;
    return false;
}


