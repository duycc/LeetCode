/**
 * @file     lc_0034.cpp
 * @brief    https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return std::vector<int>{lowerBound(nums, target), upperBound(nums, target)};
    }

  private:
    int lowerBound(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (left < nums.size()) && (nums[left] == target) ? left : -1;
    }

    int upperBound(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (left - 1 >= 0) && (nums[left - 1] == target) ? left - 1 : -1;
    }
};
