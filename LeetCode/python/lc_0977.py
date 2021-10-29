"""
 * @file     lc_0977.py
 * @brief    https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 * @author   YongDu
 * @date     2021-09-09
"""


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l, r, k = 0, len(nums) - 1, len(nums) - 1
        res = [-1] * len(nums)
        while l <= r:
            lpro = nums[l] ** 2
            rpro = nums[r] ** 2
            if lpro > rpro:
                res[k] = lpro
                l += 1
            else:
                res[k] = rpro
                r -= 1
            k -= 1
        return res
