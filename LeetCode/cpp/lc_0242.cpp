/**
 * @file     lc_0242.cpp
 * @brief    https://leetcode-cn.com/problems/valid-anagram/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::unordered_map<char, int> charMap;
    for (int i = 0; i < s.size(); ++i) {
      charMap[s[i]]++;
      charMap[t[i]]--;
    }
    for (auto &[ch, count] : charMap) {
      if (count != 0) {
        return false;
      }
    }
    return true;
  }
};
