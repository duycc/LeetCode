/**
 * @file     hj008.cpp
 * @brief
 * @author   DuYong
 * @date     2021-05-01
 */
#include <iostream>
#include <map>
using namespace std;

int main() {
    int size{0};
    while (cin >> size) {
        int                key, value;
        std::map<int, int> hashMap;
        while (cin >> key >> value) {
            hashMap[key] += value;
        }
        for (auto kv : hashMap) {
            cout << kv.first << " " << kv.second << endl;
        }
    }

    return 0;
}