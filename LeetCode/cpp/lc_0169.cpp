/**
 * @file     lc_0169.cpp
 * @brief    https://leetcode-cn.com/problems/majority-element/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};
