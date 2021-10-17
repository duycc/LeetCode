/**
 * @file     lc_1005.cpp
 * @brief    https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [Greedy Method] ----------------------------===//
// 1. 先按绝对值大小排序
// 2. 最后反复修改绝对值最小的那个元素
//===----------------------------------------------------------------------===//
class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end(), [](int lhs, int rhs) { return std::abs(lhs) > std::abs(rhs); });
    for (int i = 0; i < nums.size() && k > 0; ++i) {
      if (nums[i] < 0) {
        nums[i] *= -1;
        k--;
      }
    }
    while (k > 0) {
      nums[nums.size() - 1] *= -1;
      k--;
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
  }
};
