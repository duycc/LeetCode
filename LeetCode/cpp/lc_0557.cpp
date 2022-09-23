/**
 * @file     lc_0557.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * @author   YongDu
 * @date     2021-09-09
 */
class Solution {
  public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size();) {
            int j = i;
            while (s[j] != ' ' && j < s.size()) {
                j++;
            }
            std::reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};
