/**
 * @file     lc_0034.cpp
 * @brief    https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int lower = lowerBound(nums, target);
    int upper = upperBound(nums, target);
    if (-1 == lower || -1 == upper) {
      return vector<int>{-1, -1};
    }
    return vector<int>{lower, upper};
  }

private:
  int lowerBound(vector<int> &nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return (left < nums.size() && nums[left] == target) ? left : -1;
  }

  int upperBound(vector<int> &nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return (left - 1 >= 0 && nums[left - 1] == target) ? left - 1 : -1;
  }
};
