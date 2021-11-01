/**
 * @file     lc_0518.cpp
 * @brief    https://leetcode-cn.com/problems/coin-change-2/
 * @author   YongDu
 * @date     2021-09-28
 */

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    // 先遍历物品，再遍历背包，防止出现重复的硬币组合
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = coins[i]; j <= amount; ++j) {
        dp[j] += dp[j - coins[i]];
      }
    }
    return dp[amount];
  }
};
