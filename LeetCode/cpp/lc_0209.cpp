/**
 * @file     lc_0209.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * @author   YongDu
 * @date     2021-09-07
 */
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    // 滑动窗口
    int minLen = INT_MAX;
    int i = 0;
    int sum = 0;
    for (int j = 0; j < nums.size(); ++j) {
      sum += nums[j];
      while (sum >= target) {
        int subLen = j - i + 1;
        minLen = subLen < minLen ? subLen : minLen;
        sum -= nums[i++];
      }
    }
    return minLen == INT_MAX ? 0 : minLen;
  }
};
