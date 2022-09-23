/**
 * @file     lc_0189.cpp
 * @brief    https://leetcode-cn.com/problems/rotate-array/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
        return;
    }
};
