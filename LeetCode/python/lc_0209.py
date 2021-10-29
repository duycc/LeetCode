"""
 * @file     lc_0209.py
 * @brief    https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * @author   YongDu
 * @date     2021-09-09
"""


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_len = sys.maxsize
        left = 0
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            while(sum >= target):
                min_len = min(i - left + 1, min_len)
                sum -= nums[left]
                left += 1
            i += 1
        return min_len if min_len != sys.maxsize else 0
