/**
 * @file     ig_0102.cpp
 * @brief    https://leetcode-cn.com/problems/check-permutation-lcci/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  bool CheckPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) {
      return false;
    }

    unordered_map<char, int> hashMapA;
    unordered_map<char, int> hashMapB;
    for (int i{}; i < s1.length(); i++) {
      hashMapA[s1[i]]++;
      hashMapB[s2[i]]++;
    }
    if (hashMapA.size() != hashMapB.size()) {
      return false;
    }

    for (auto it = hashMapA.begin(); it != hashMapA.end(); ++it) {
      if (it->second != hashMapB[it->first]) {
        return false;
      }
    }

    return true;
  }
};
