/**
 * @file     lc_0541.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-string-ii/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
      if (i + k <= s.size()) {
        std::reverse(s.begin() + i, s.begin() + i + k);
      } else {
        std::reverse(s.begin() + i, s.end());
      }
    }
    return s;
  }
};
