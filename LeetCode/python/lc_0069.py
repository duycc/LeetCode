"""
 * @file     lc_0069.py
 * @brief    
 * @author   YongDu
 * @date     2021-10-25
"""


class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        left, right = 1, x
        while left <= right:
            mid = left + ((right - left) >> 1)
            sqrt = x // mid
            if sqrt == mid:
                return sqrt
            elif sqrt < mid:
                right = mid - 1
            else:
                left = mid + 1

        return right
