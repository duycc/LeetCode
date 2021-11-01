/**
 * @file     lc_0213.cpp
 * @brief    https://leetcode-cn.com/problems/house-robber-ii/
 * @author   YongDu
 * @date     2021-11-01
 */

class Solution {
public:
  int rob(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) {
      return 0;
    }
    if (len == 1) {
      return nums[0];
    }
    return std::max(robRange(nums, 0, len - 2), robRange(nums, 1, len - 1));
  }

private:
  int robRange(const vector<int> &nums, int begin, int end) {
    if (begin == end) {
      return nums[begin];
    }
    vector<int> dp(nums.size(), 0);
    dp[begin] = nums[begin];
    dp[begin + 1] = std::max(nums[begin], nums[begin + 1]);
    for (int i = begin + 2; i <= end; ++i) {
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
  }
};
