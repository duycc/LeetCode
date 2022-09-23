/**
 * @file     lc_0075.cpp
 * @brief    https://leetcode-cn.com/problems/sort-colors/
 * @author   YongDu
 * @date     2021-09-11
 */
/*
    双指针遍历
    0交换到最前面，2交换到右边，交换2时，需注意右边交换过来的元素仍然是2
*/
class Solution {
  public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for (int i = 0; i <= right; ++i) {
            while (i <= right && nums[i] == 2) {
                std::swap(nums[i], nums[right]);
                right--;
            }
            if (nums[i] == 0) {
                std::swap(nums[i], nums[left]);
                left++;
            }
        }
    }
};
