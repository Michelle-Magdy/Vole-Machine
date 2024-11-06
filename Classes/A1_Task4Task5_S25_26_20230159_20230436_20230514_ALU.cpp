#include<iostream>
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_ALU.h"
#include "A1_Task4Task5_S25_26_20230159_20230436_20230514_REGISTER.h"

using namespace std;


string ALU::hexToBinary(const string &hex) {
    // Create a string to hold the binary result
    string binary;

    for (char digit: hex) {
        // Use bitset to convert hex to binary
        switch (toupper(digit)) {
            case '0':
                binary += "0000";
                break;
            case '1':
                binary += "0001";
                break;
            case '2':
                binary += "0010";
                break;
            case '3':
                binary += "0011";
                break;
            case '4':
                binary += "0100";
                break;
            case '5':
                binary += "0101";
                break;
            case '6':
                binary += "0110";
                break;
            case '7':
                binary += "0111";
                break;
            case '8':
                binary += "1000";
                break;
            case '9':
                binary += "1001";
                break;
            case 'A':
                binary += "1010";
                break;
            case 'B':
                binary += "1011";
                break;
            case 'C':
                binary += "1100";
                break;
            case 'D':
                binary += "1101";
                break;
            case 'E':
                binary += "1110";
                break;
            case 'F':
                binary += "1111";
                break;
            default:
                cout << "Invalid hexadecimal digit: " << digit << endl;
                return "";
        }
    }

    return binary;
}

string ALU::binaryToHex(const string &binary) {
    stringstream ss;
    int decimal = stoi(binary, nullptr, 2);
    ss << hex << uppercase << setw(2) << setfill('0') << (decimal & 0xFF);
    return ss.str();
}

string ALU::addBinary(const string &bin1, const string &bin2) {

    int num1 = stoi(bin1, nullptr, 2);
    int num2 = stoi(bin2, nullptr, 2);


    int result = num1 + num2;
    if (result < 0) result += 256;

    return bitset<8>(result & 0xFF).to_string();
}


string ALU::hex_to_dec(const string &hexStr) {
    int decimal;
    stringstream ss;

    ss << hex << hexStr;
    ss >> decimal;

    return to_string(decimal);
}


string ALU::dec_to_hex(const string &decimalValue) {
    int decimalInt;
    stringstream ss;


    ss << decimalValue;
    ss >> decimalInt;


    ss.clear();
    ss.str("");

    ss << hex << uppercase << decimalInt;


    return ss.str();
}

void ALU::Rotate(int idxReg, Register &R, int shift) {
    string cell = hexToBinary(R.getCell(idxReg));
    for (int i = 0; i < shift; ++i) {
        char c = cell.back();
        cell.pop_back();
        cell = c + cell;
    }
    cell = binaryToHex(cell);
    R.setCell(idxReg, cell);
}

void ALU::addfloat(int idx1, int idx2, int idx3, Register &reg) {

    string bin1 = hexToBinary(reg.getCell(idx2));
    string bin2 = hexToBinary(reg.getCell(idx3));


    bool sign1 = bin1[0] == '1';
    bool sign2 = bin2[0] == '1';
    int exp1 = stoi(bin1.substr(1, 3), nullptr, 2);
    int exp2 = stoi(bin2.substr(1, 3), nullptr, 2);
    int mant1 = stoi(bin1.substr(4, 4), nullptr, 2);
    int mant2 = stoi(bin2.substr(4, 4), nullptr, 2);


    double val1 = (mant1 / 16.0) * pow(2, exp1 - 4) * (sign1 ? -1 : 1);
    double val2 = (mant2 / 16.0) * pow(2, exp2 - 4) * (sign2 ? -1 : 1);


    double sum = val1 + val2;

    bool resultSign = sum < 0;
    sum = fabs(sum);


    int resultExp = 0;
    while (sum >= 1.0) {
        sum /= 2.0;
        resultExp++;
    }
    while (sum < 0.5 && resultExp > -4) {
        sum *= 2.0;
        resultExp--;
    }


    resultExp += 4;

    resultExp = max(0, min(7, resultExp));

    int resultMant = round(sum * 16);
    resultMant = max(0, min(15, resultMant));


    string resultBin = string(1, resultSign ? '1' : '0') +
                       bitset<3>(resultExp).to_string() +
                       bitset<4>(resultMant).to_string();


    reg.setCell(idx1, binaryToHex(resultBin));
}


void ALU::add(int idx1, int idx2, int idx3, Register &reg) {
    string bin1 = hexToBinary(reg.getCell(idx2));
    string bin2 = hexToBinary(reg.getCell(idx3));
    string binaryResult = addBinary(bin1, bin2);
    string hexResult = binaryToHex(binaryResult);
    reg.setCell(idx1, hexResult);
}

void ALU::AND(int idxReg1, int idxReg2, int idxReg3, Register &R) {
    int a = stoi(hex_to_dec(R.getCell(idxReg2))) & stoi(hex_to_dec(R.getCell(idxReg3)));
    R.setCell(idxReg1, dec_to_hex(to_string(a)));
}

void ALU::OR(int idxReg1, int idxReg2, int idxReg3, Register &R) {
    int a = stoi(hex_to_dec(R.getCell(idxReg2))) | stoi(hex_to_dec(R.getCell(idxReg3)));
    R.setCell(idxReg1, dec_to_hex(to_string(a)));
}

void ALU::XOR(int idxReg1, int idxReg2, int idxReg3, Register &R) {
    int a = stoi(hex_to_dec(R.getCell(idxReg2))) ^ stoi(hex_to_dec(R.getCell(idxReg3)));
    R.setCell(idxReg1, dec_to_hex(to_string(a)));
}
