/**
 * @file     lc_0518.cpp
 * @brief    https://leetcode-cn.com/problems/coin-change-2/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  int change(int amount, vector<int> &coins) {
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
