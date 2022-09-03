/**
 * @file     lc_0283.cpp
 * @brief    https://leetcode-cn.com/problems/move-zeroes/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        for (int i = index; i < nums.size(); ++i) {
            nums[i] = 0;
        }
        return;
    }
};
