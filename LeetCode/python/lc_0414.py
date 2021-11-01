"""
 * @file     lc_0414.py
 * @brief    https://leetcode-cn.com/problems/third-maximum-number/
 * @author   YongDu
 * @date     2021-11-01
"""


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        n1st = n2nd = n3rd = -sys.maxsize - 1

        for n in nums:
            if n > n1st:
                n3rd, n2nd, n1st = n2nd, n1st, n
            elif n > n2nd and n < n1st:
                n3rd, n2nd = n2nd, n
            elif n > n3rd and n < n2nd:
                n3rd = n

        return n3rd if n3rd != -sys.maxsize - 1 else n1st
