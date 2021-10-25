"""
 * @file     lc_0367.py
 * @brief    
 * @author   YongDu
 * @date     2021-10-25
"""


class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num <= 0:
            return False
        left, right = 1, num
        while left <= right:
            mid = left + ((right - left) >> 1)
            sqrt = num / mid
            if sqrt == mid and num % sqrt == 0:
                return True
            elif sqrt < mid:
                right = mid - 1
            else:
                left = mid + 1

        return False
