/**
 * @file     lc_0070.cpp
 * @brief    https://leetcode-cn.com/problems/climbing-stairs/
 * @author   YongDu
 * @date     2021-09-28
 */

//===------------------------- [dp] ---------------------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  int climbStairs(int n) {
    //  普通dp
    if (n == 1 || n == 2) {
      return n;
    }
    int n1st = 1, n2nd = 2;
    int res = 0;
    for (int i = 3; i <= n; ++i) {
      res = n1st + n2nd;
      n1st = n2nd;
      n2nd = res;
    }
    return res;
  }
};

//===------------------------- [完全背包] ----------------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  int climbStairs(int n) {
    // 完全背包
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= n; ++j) {
      for (int i = 1; i <= 2; ++i) {
        if (j >= i) {
          dp[j] += dp[j - i];
        }
      }
    }
    return dp[n];
  }
};
