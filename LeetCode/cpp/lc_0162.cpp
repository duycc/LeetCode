/**
 * @file     lc_0162.cpp
 * @brief    https://leetcode-cn.com/problems/find-peak-element/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
        return mid;
      } else if (nums[mid] < nums[mid + 1]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
};
