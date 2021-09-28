/**
 * @file     lc_0070.cpp
 * @brief    https://leetcode-cn.com/problems/climbing-stairs/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) {
      return n;
    }
    int x = 1, y = 2;
    int countN = 0;
    for (int i = 3; i <= n; ++i) {
      countN = x + y;
      x = y;
      y = countN;
    }
    return countN;
  }
};
