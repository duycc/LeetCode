/**
 * @file     lc_0977.cpp
 * @brief    https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    vector<int> sortedSquares(vector<int>& nums) {
        int              len = nums.size();
        std::vector<int> result(len);
        int              k = len - 1;
        for (int i = 0, j = len - 1; i <= j;) {
            if (std::pow(nums[i], 2) >= std::pow(nums[j], 2)) {
                result[k--] = std::pow(nums[i++], 2);
            } else {
                result[k--] = std::pow(nums[j--], 2);
            }
        }
        return result;
    }
};
