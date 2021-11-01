/**
 * @file     lc_0279.cpp
 * @brief    https://leetcode-cn.com/problems/perfect-squares/
 * @author   YongDu
 * @date     2021-11-01
 */

class Solution {
public:
  int numSquares(int n) {
    // 完全背包 - 组合问题
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i * i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (j - i * i >= 0) {
          dp[j] = std::min(dp[j - i * i] + 1, dp[j]);
        }
      }
    }
    return dp[n] != INT_MAX ? dp[n] : -1;
  }
};
