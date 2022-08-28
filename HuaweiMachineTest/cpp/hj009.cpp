/**
 * @file     hj009.cpp
 * @brief
 * @author   DuYong
 * @date     2021-05-01
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    std::string inNum;
    while (cin >> inNum) {
        std::string outNum;
        for (auto&& iter = inNum.rbegin(); iter != inNum.rend(); ++iter) {
            if (outNum.find(*iter) == string::npos) {
                outNum.push_back(*iter);
            }
        }
        cout << outNum << endl;
    }
    return 0;
}