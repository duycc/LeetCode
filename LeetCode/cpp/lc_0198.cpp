/**
 * @file     lc_0198.cpp
 * @brief    https://leetcode-cn.com/problems/house-robber/
 * @author   YongDu
 * @date     2021-11-01
 */

class Solution {
public:
  int rob(vector<int> &nums) {
    // dp
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
  }
};
