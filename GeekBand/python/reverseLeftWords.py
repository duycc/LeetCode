"""
 * @file     reverseLeftWords.py
 * @brief    https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 * @author   YongDu
 * @date     2021-08-18
"""


class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        offset = n % len(s)
        return s[offset:] + s[:offset]
