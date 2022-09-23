/**
 * @file     lc_0027.cpp
 * @brief    https://leetcode-cn.com/problems/remove-element/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int n : nums) {
            if (n != val) {
                nums[len++] = n;
            }
        }
        return len;
    }
};