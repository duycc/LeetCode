/**
 * @file     lc_0053.cpp
 * @brief    https://leetcode-cn.com/problems/maximum-subarray/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> result(nums.size());
    result[0] = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      result[i] = std::max(nums[i], result[i - 1] + nums[i]);
      maxSum = std::max(result[i], maxSum);
    }
    return maxSum;
  }
};
