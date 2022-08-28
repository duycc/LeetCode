/**
 * @file     hj003.cpp
 * @brief
 * @author   DuYong
 * @date     2021-04-27
 */
#include <iostream>
#include <set>

using namespace std;

int main() {
    int num;
    cin >> num;
    std::set<int> numSet;
    while (cin >> num) {
        numSet.emplace(num);
    }
    for (int n : numSet) {
        cout << n << endl;
    }

    return 0;
}
