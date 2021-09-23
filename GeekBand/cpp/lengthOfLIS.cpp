/**
 * @file     lengthOfLIS.cpp
 * @brief    https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * @author   YongDu
 * @date     2021-08-31
 */
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int maxLen = 1;
    vector<int> result(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          result[i] = std::max(result[i], result[j] + 1);
        }
      }
      maxLen = std::max(maxLen, result[i]);
    }
    return maxLen;
  }
};
