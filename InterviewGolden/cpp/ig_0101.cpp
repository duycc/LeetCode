/**
 * @file     ig_0101.cpp
 * @brief    https://leetcode-cn.com/problems/is-unique-lcci/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  bool isUnique(string astr) {
    bitset<256> hashMap;
    for (int i{}; i < astr.length(); ++i) {
      if (hashMap[(int)astr[i]]) {
        return false;
      }
      hashMap[(int)astr[i]] = 1;
    }

    return true;
  }
};
