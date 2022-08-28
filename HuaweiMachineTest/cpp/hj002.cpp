/**
 * @file     hj002.cpp
 * @brief
 * @author   DuYong
 * @date     2021-04-27
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    std::string str;
    getline(cin, str);
    char ch = std::tolower(getchar());
    int  count{0};
    for (char c : str) {
        if (std::tolower(c) == ch) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}