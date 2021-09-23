/**
 * @file     jz_058.cpp
 * @brief    https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * @author   YongDu
 * @date     2021-09-09
 */
class Solution {
public:
  string reverseLeftWords(string s, int n) {
    n = n % s.size();
    std::reverse(s.begin(), s.begin() + n);
    std::reverse(s.begin() + n, s.end());
    std::reverse(s.begin(), s.end());
    return s;
  }
};
