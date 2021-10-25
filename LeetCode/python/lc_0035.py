"""
 * @file     lc_0035.py
 * @brief    
 * @author   YongDu
 * @date     2021-10-25
"""


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # >= target
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + ((right - left) >> 1)
            if nums[mid] >= target:
                right = mid - 1
            else:
                left = mid + 1

        return left
