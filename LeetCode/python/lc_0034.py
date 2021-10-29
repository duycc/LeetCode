"""
 * @file     lc_0034.py
 * @brief    
 * @author   YongDu
 * @date     2021-10-29
"""


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def lower_bound(nums, target):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + ((right - left) >> 1)
                if nums[mid] >= target:
                    right = mid - 1
                else:
                    left = mid + 1
            return left if left < len(nums) and nums[left] == target else -1

        def upper_bound(nums, target):
            left, right = 0, len(nums) - 1
            while left <= right:
                mid = left + ((right - left) >> 1)
                if nums[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
            return left - 1 if left - 1 >= 0 and nums[left - 1] == target else -1

        lower, upper = lower_bound(nums, target), upper_bound(nums, target)

        return [-1, -1] if lower == -1 or upper == -1 else [lower, upper]
