/**
 * @file     lc_0153.cpp
 * @brief    https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int findMin(vector<int> &nums) {
    if (nums.size() == 1 || nums[0] < nums[nums.size() - 1]) {
      return nums[0];
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] >= nums[0]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return nums[left];
  }
};
