/**
 * @file     coinChange2.cpp
 * @brief    https://leetcode-cn.com/problems/coin-change-2/
 * @author   YongDu
 * @date     2021-08-15
 */
class Solution {
public:
  int change(int amount, vector<int> &coins) {
    // 组合问题，先遍历物品，再遍历背包
    vector<int> result(amount + 1, 0);
    result[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = coins[i]; j <= amount; ++j) {
        result[j] += result[j - coins[i]];
      }
    }
    return result[amount];
  }
};
