/**
 * @file     lc_0322.cpp
 * @brief    https://leetcode-cn.com/problems/coin-change/
 * @author   YongDu
 * @date     2021-09-28
 */

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // 完全背包 - 组合问题
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < coins.size(); ++i) {
      for (int j = coins[i]; j <= amount; ++j) {
        if (dp[j - coins[i]] != INT_MAX) {
          dp[j] = std::min(dp[j - coins[i]] + 1, dp[j]);
        }
      }
    }

    return dp[amount] != INT_MAX ? dp[amount] : -1;
  }
};
