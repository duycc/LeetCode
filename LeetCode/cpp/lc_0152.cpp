/**
 * @file     lc_0152.cpp
 * @brief    https://leetcode-cn.com/problems/maximum-product-subarray/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
  public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0];
        int minPro = nums[0];
        int maxValue = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int preMaxPro = maxPro; // 注意保存，在求解 minPro 时，maxPro 已经改变
            maxPro = std::max(std::max(preMaxPro * nums[i], minPro * nums[i]), nums[i]);
            minPro = std::min(std::min(preMaxPro * nums[i], minPro * nums[i]), nums[i]);
            maxValue = std::max(maxValue, maxPro);
        }
        return maxValue;
    }
};
