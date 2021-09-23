"""
 * @file     reverseWords.py
 * @brief    https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 * @author   YongDu
 * @date     2021-08-18
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(word[::-1] for word in s.split(' '))
