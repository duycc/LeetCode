"""
 * @file     lc_0041.py
 * @brief    https://leetcode-cn.com/problems/first-missing-positive/
 * @author   YongDu
 * @date     2021-11-01
"""


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:

        n = len(nums)
        for i in range(n):
            if nums[i] <= 0:
                nums[i] = n + 1

        for i in range(n):
            num = abs(nums[i])
            if num < n + 1:
                nums[num - 1] = -abs(nums[num - 1])

        for i in range(n):
            if nums[i] > 0:
                return i + 1

        return n + 1
