# -*- coding: utf-8 -*-
"""
 * @file     CheckPermutation.py
 * @brief    
 * @author   YongDu
 * @date     2021-07-25
"""


class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        hash_map = collections.defaultdict(int)

        for ch in s1:
            hash_map[ch] += 1
        for ch in s2:
            hash_map[ch] -= 1

        for val in hash_map.values():
            if val != 0:
                return False

        return True
