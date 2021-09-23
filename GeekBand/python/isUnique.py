# -*- coding: utf-8 -*-
"""
 * @file     isUnique.py
 * @brief    
 * @author   YongDu
 * @date     2021-07-25
"""


class Solution:
    def isUnique(self, astr: str) -> bool:
        return True if (len(set(astr)) == len(astr)) else False
