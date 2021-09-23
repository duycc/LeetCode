"""
 * @file     lc_0209.py
 * @brief    https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * @author   YongDu
 * @date     2021-09-09
"""


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        res = float("inf")
        sum = 0
        index = 0
        for i in range(len(nums)):
            sum += nums[i]
            while sum >= target:
                res = min(res, i - index + 1)
                sum -= nums[index]
                index += 1
        return 0 if res == float("inf") else res
