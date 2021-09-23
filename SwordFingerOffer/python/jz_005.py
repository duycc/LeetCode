"""
 * @file     replaceSpace.py
 * @brief    https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * @author   YongDu
 * @date     2021-08-18
"""


class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(' ', '%20')
