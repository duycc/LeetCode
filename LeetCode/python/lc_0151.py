"""
 * @file     lc_0151.py
 * @brief    https://leetcode-cn.com/problems/reverse-words-in-a-string/
 * @author   YongDu
 * @date     2021-09-09
"""


class Solution:
    # 去除多余空格
    def trim_spaces(self, s):
        n = len(s)
        left = 0
        right = n - 1
        while left <= right and s[left] == ' ':
            left += 1
        while left <= right and s[right] == ' ':
            right -= 1
        tmp = []
        while left <= right:
            if s[left] != ' ':
                tmp.append(s[left])
            elif tmp[-1] != ' ':
                tmp.append(s[left])
            left += 1
        return tmp

    # 反转字符数组
    def reverse_string(self, nums, left, right):
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
        return None

    # 反转每个单词
    def reveverse_each_word(self, nums):
        start = 0
        end = 0
        n = len(nums)
        while start < n:
            while end < n and nums[end] != ' ':
                end += 1
            self.reverse_string(nums, start, end)
            start = end + 1
            end += 1
        return None

    def reverseWords(self, s: str) -> str:
        l = self.trim_spaces(s)
        self.reverse_string(l, 0, len(l) - 1)
        self.reveverse_each_word(l)
        return ' '.join(l)
