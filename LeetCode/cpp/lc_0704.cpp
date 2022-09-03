/**
 * @file     lc_0704.cpp
 * @brief    https://leetcode-cn.com/problems/binary-search/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
