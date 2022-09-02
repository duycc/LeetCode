/**
 * @file     hj015.cpp
 * @brief
 * @author   DuYong
 * @date     2021-05-01
 */
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int32_t num;
    cin >> num;
    std::bitset<32> b(num);
    cout << b.count() << endl;

    return 0;
}