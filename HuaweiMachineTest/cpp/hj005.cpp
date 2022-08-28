/**
 * @file     hj005.cpp
 * @brief
 * @author   DuYong
 * @date     2021-05-01
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int32_t hexToDec(std::string& hexNum) {
    int     bit{0};
    int32_t decNum{0};
    for (int i = hexNum.size() - 1; i > 1; --i) {
        if (std::isdigit(hexNum[i])) {
            decNum += (hexNum[i] - '0') * std::pow(16, bit++);
        } else {
            decNum += (hexNum[i] - 'A' + 10) * std::pow(16, bit++);
        }
    }
    return decNum;
}

int main() {
    std::string hexNum;
    while (cin >> hexNum) {
        cout << hexToDec(hexNum) << endl;
    }
    return 0;
}