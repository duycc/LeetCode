/**
 * @file     lc_0344.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-string/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  void reverseString(vector<char> &s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      std::swap(s[i], s[j]);
    }
    return;
  }
};
