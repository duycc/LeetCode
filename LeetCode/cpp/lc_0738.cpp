/**
 * @file     lc_0738.cpp
 * @brief    https://leetcode-cn.com/problems/monotone-increasing-digits/
 * @author   YongDu
 * @date     2021-10-18
 */
class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    std::string s = std::to_string(n);
    int flag = s.size(); // 标记需要被赋值为9的元素开始位置
    for (int i = s.size() - 1; i > 0; --i) {
      if (s[i - 1] > s[i]) {
        flag = i;
        s[i - 1]--;
      }
    }
    for (int i = flag; i < s.size(); ++i) {
      s[i] = '9';
    }
    return std::stoi(s);
  }
};
