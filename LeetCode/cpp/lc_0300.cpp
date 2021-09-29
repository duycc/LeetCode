/**
 * @file     lc_0300.cpp
 * @brief    https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int maxLen = 1;
    vector<int> result(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          result[i] = std::max(result[j] + 1, result[i]);
        }
      }
      maxLen = std::max(result[i], maxLen);
    }
    return maxLen;
  }
};
