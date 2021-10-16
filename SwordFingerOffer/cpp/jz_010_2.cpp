/**
 * @file     jz_010_2.cpp
 * @brief    https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
 * @author   YongDu
 * @date     2021-10-16
 */
class Solution {
public:
  int numWays(int n) {
    if (n == 0 || n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    int num1st = 1;
    int num2nd = 2;
    int nWays = 0;
    for (int i = 3; i <= n; ++i) {
      nWays = (num1st + num2nd) % 1000000007;
      num1st = num2nd;
      num2nd = nWays;
    }
    return nWays;
  }
};
