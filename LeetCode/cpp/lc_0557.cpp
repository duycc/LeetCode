/**
 * @file     lc_0557.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  string reverseWords(string s) {
    int start = 0;

    for (int i{}; i < s.size(); ++i) {
      if (s[i] == ' ') {
        reverseWord(s, start, i - 1);
        start = i + 1;
      }

      if (i == s.size() - 1) {
        reverseWord(s, start, i);
      }
    }

    return s;
  }

  void reverseWord(string &str, int l, int r) {
    while (l < r) {
      swap(str[l], str[r]);
      l++;
      r--;
    }
    return;
  }
};
