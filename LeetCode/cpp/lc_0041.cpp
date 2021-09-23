/**
 * @file     lc_0041.cpp
 * @brief    https://leetcode-cn.com/problems/first-missing-positive/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (auto &num : nums) {
      if (num <= 0) {
        num = n + 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      int num = std::abs(nums[i]);
      if (num < n + 1) {
        nums[num - 1] = -std::abs(nums[num - 1]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }

    return n + 1;
  }
};
