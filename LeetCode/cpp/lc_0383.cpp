/**
 * @file     lc_0383.cpp
 * @brief    https://leetcode-cn.com/problems/ransom-note/
 * @author   YongDu
 * @date     2021-09-08
 */

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> charMap;
        for (char ch : magazine) {
            charMap[ch]++;
        }
        for (char ch : ransomNote) {
            charMap[ch]--;
            if (charMap[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};
