/**
 * @file     lc_1137.cpp
 * @brief    https://leetcode-cn.com/problems/n-th-tribonacci-number/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    }
    if (n == 1 || n == 2) {
      return 1;
    }

    int x = 0, y = 1, z = 1;
    int tibN = 0;
    for (int i = 3; i <= n; ++i) {
      tibN = x + y + z;
      x = y;
      y = z;
      z = tibN;
    }
    return tibN;
  }
};
