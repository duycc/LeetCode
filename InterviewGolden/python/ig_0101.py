# -*- coding: utf-8 -*-
"""
 * @file     isUnique.py
 * @brief    https://leetcode-cn.com/problems/is-unique-lcci/
 * @author   YongDu
 * @date     2021-07-25
"""


class Solution:
    def isUnique(self, astr: str) -> bool:
        return True if (len(set(astr)) == len(astr)) else False
