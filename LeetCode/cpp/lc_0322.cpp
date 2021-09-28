/**
 * @file     lc_0322.cpp
 * @brief    https://leetcode-cn.com/problems/coin-change/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // 动态规划
    vector<int> result(amount + 1, INT_MAX);
    result[0] = 0;
    int coinsNum = coins.size();

    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < coinsNum; ++j) {
        if (i >= coins[j] && result[i - coins[j]] != INT_MAX) {
          result[i] = std::min(result[i], result[i - coins[j]] + 1);
        }
      }
    }

    return result[amount] != INT_MAX ? result[amount] : -1;
  }
};
