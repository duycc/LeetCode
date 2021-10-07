/**
 * @file     lc_0434.cpp
 * @brief    https://leetcode-cn.com/problems/number-of-segments-in-a-string/
 * @author   YongDu
 * @date     2021-10-07
 */
class Solution {
public:
  int countSegments(string s) {
    int wordNum = 0;
    for (int i = 0; i < s.size(); ++i) {
      if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
        wordNum++;
      }
    }
    return wordNum;
  }
};
