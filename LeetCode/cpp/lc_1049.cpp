/**
 * @file     lc_1049.cpp
 * @brief    https://leetcode-cn.com/problems/last-stone-weight-ii/
 * @author   YongDu
 * @date     2021-10-24
 */
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int totalWeight = 0;
    for (auto stone : stones) {
      totalWeight += stone;
    }
    int target = totalWeight >> 1;
    vector<int> dp(15001, 0);
    for (int i = 0; i < stones.size(); ++i) {
      for (int j = target; j >= stones[i]; --j) {
        dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return totalWeight - dp[target] - dp[target];
  }
};
