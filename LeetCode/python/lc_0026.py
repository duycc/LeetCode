"""
 * @file     lc_0026.py
 * @brief    
 * @author   YongDu
 * @date     2021-10-29
"""


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        index = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[index]:
                index += 1
                nums[index] = nums[i]
        return index + 1
