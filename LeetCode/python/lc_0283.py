"""
 * @file     lc_0283.py
 * @brief    
 * @author   YongDu
 * @date     2021-10-29
"""


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[index] = nums[i]
                index += 1

        for i in range(index, len(nums)):
            nums[index] = 0
            index += 1
