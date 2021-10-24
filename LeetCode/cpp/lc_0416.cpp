/**
 * @file     lc_0416.cpp
 * @brief    https://leetcode-cn.com/problems/partition-equal-subset-sum/
 * @author   YongDu
 * @date     2021-10-24
 */
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    if (sum % 2 != 0) {
      return false;
    }
    int target = sum >> 1;

    // 0-1背包
    vector<int> dp(10001, 0);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[target] == target;
  }
};
