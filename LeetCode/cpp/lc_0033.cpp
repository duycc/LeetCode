/**
 * @file     lc_0033.cpp
 * @brief    https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[left] <= nums[mid]) { // the bottom half is sorted
        if (target >= nums[left] && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else { // the upper half is sorted
        if (target > nums[mid] && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};
