#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MACHINE_INSTRUCTION.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_REGISTER.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_MEMORY.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_ALU.h"

using namespace std;

void MachineInstruction::Load(int idxReg, int idxMem, Register &R, Memory &M) {
    string cell = M.getCell(idxMem);
    R.setCell(idxReg, cell);
}

void MachineInstruction::Load(int idxReg, const string &val, Register &R) {
    R.setCell(idxReg, val);
}

void MachineInstruction::Store(int idxReg, int idxMem, Register &R, Memory &M) {
    string cell = R.getCell(idxReg);
    M.setCell(idxMem, cell);
}

void MachineInstruction::Move(int idxReg1, int idxReg2, Register &R) {
    R.setCell(idxReg2, R.getCell(idxReg1));
}

void MachineInstruction::JumpB(int idxReg, int idxMem, Register &R, int &PC) {
    int regVal = stoi(ALU::hex_to_dec(R.getCell(idxReg)));
    int r0Val = stoi(ALU::hex_to_dec(R.getCell(0)));

    if (regVal == r0Val) {
        PC = idxMem;
    }
}

void MachineInstruction::JumpD(int idxReg, int idxMem, Register &R, int &PC) {
    int regVal = std::stoi(ALU::hex_to_dec(R.getCell(idxReg)));
    int r0Val = std::stoi(ALU::hex_to_dec(R.getCell(0)));

    if (regVal > r0Val) {
        PC = idxMem;
    }
}

bool MachineInstruction::Halt() {
    return true;
}
