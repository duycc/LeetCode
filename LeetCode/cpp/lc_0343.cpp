/**
 * @file     lc_0343.cpp
 * @brief    https://leetcode-cn.com/problems/integer-break/
 * @author   YongDu
 * @date     2021-10-21
 */
class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
      }
    }
    return dp[n];
  }
};
