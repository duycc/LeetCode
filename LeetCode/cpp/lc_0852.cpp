/**
 * @file     lc_0852.cpp
 * @brief    https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
 * @author   YongDu
 * @date     2021-09-11
 */
/**
 * @file     peakIndexInMountainArray.cpp
 * @brief
 * @author   DuYong
 * @date     2021-03-12
 */
class Solution {
public:
  int peakIndexInMountainArray(vector<int> &nums) {
    int left = 1;
    int right = nums.size() - 2;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
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
