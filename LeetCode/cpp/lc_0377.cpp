/**
 * @file     lc_0377.cpp
 * @brief    https://leetcode-cn.com/problems/combination-sum-iv/
 * @author   YongDu
 * @date     2021-11-01
 */

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // 求排列数，外层先遍历背包
    for (int j = 1; j <= target; ++j) {
      for (int i = 0; i < nums.size(); ++i) {
        if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]]) { // 防止溢出
          dp[j] += dp[j - nums[i]];
        }
      }
    }
    return dp[target];
  }
};
