"""
 * @file     longestConsecutive.py
 * @brief    https://leetcode-cn.com/problems/longest-consecutive-sequence/
 * @author   YongDu
 * @date     2021-08-18
"""


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hash_tab = set(nums)
        max_len = 0
        for num in hash_tab:
            if num - 1 in hash_tab:
                continue
            start = num
            while start in hash_tab:
                start += 1
            max_len = max(max_len, start - num)
        return max_len
