/**
 * @file     sortColors.cpp
 * @brief    https://leetcode-cn.com/problems/sort-colors/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int right = nums.size() - 1;
    int left = 0;
    for (int i = 0; i <= right; ++i) {
      while (i <= right && nums[i] == 2) {
        std::swap(nums[i], nums[right]);
        --right;
      }
      if (nums[i] == 0) {
        std::swap(nums[i], nums[left]);
        ++left;
      }
    }
    return;
  }
};
