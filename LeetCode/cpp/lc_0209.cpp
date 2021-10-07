/**
 * @file     lc_0209.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * @author   YongDu
 * @date     2021-09-07
 */
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int minLen = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < nums.size(); ++right) {
      sum += nums[right];
      // 缩小滑动窗口
      while (sum >= target) {
        minLen = std::min(right - left + 1, minLen);
        sum -= nums[left++];
      }
    }
    return minLen != INT_MAX ? minLen : 0;
  }
};
