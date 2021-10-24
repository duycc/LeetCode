/**
 * @file     lc_0494.cpp
 * @brief    https://leetcode-cn.com/problems/target-sum/
 * @author   YongDu
 * @date     2021-10-24
 */
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for (auto n : nums) {
      sum += n;
    }
    if (std::abs(target) > sum) {
      return 0;
    }
    if ((target + sum) % 2 != 0) {
      return 0;
    }
    int bagSize = (target + sum) >> 1;
    vector<int> dp(bagSize + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = bagSize; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[bagSize];
  }
};
