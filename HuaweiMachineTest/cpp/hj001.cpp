/**
 * @file     hj001.cpp
 * @brief
 * @author   DuYong
 * @date     2021-04-27
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    std::string words;
    getline(cin, words);
    auto pos = words.rfind(' ');
    cout << words.size() - 1 - pos;
    return EXIT_SUCCESS;
}