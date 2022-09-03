/**
 * @file     lc_0035.cpp
 * @brief    https://leetcode-cn.com/problems/search-insert-position/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
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
        return left;
    }
};
