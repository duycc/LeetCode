"""
 * @file     lc_0152.py
 * @brief    https://leetcode-cn.com/problems/maximum-product-subarray/
 * @author   YongDu
 * @date     2021-11-01
"""


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        min_pro = max_pro = max_val = nums[0]

        for i in range(1, len(nums)):
            pre_max_pro = max_pro
            max_pro = max(max(nums[i] * pre_max_pro,
                          nums[i] * min_pro), nums[i])
            min_pro = min(min(nums[i] * pre_max_pro,
                          nums[i] * min_pro), nums[i])
            max_val = max(max_pro, max_val)

        return max_val
