/**
 * @file     hj010.cpp
 * @brief
 * @author   DuYong
 * @date     2021-05-01
 */
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    std::string chars;
    while (cin >> chars) {
        std::unordered_set<char> chs;
        for (auto ch : chars) {
            if (ch >= 0 && ch <= 127) {
                chs.emplace(ch);
            }
        }
        cout << chs.size() << endl;
    }
    return 0;
}