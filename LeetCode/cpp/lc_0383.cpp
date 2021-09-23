/**
 * @file     lc_0383.cpp
 * @brief    https://leetcode-cn.com/problems/ransom-note/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int charMap[26]{0}; // 原生数组效率更高
    for (char ch : magazine) {
      charMap[ch - 'a']++;
    }
    for (char ch : ransomNote) {
      charMap[ch - 'a']--;
      if (charMap[ch - 'a'] < 0) { // 可提前结束遍历
        return false;
      }
    }
    return true;
  }
};
