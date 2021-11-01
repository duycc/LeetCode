"""
 * @file     lc_0059.py
 * @brief    https://leetcode-cn.com/problems/spiral-matrix-ii/
 * @author   YongDu
 * @date     2021-11-01
"""


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0] * n for _ in range(n)]
        start = 0
        value = 1

        while n > 2 * start:
            endX = endY = n - 1 - start

            for i in range(start, endX + 1):
                res[start][i] = value
                value += 1

            if endY > start:
                for i in range(start + 1, endY + 1):
                    res[i][endX] = value
                    value += 1

            if endY > start and endX > start:
                for i in range(endX - 1, start - 1, -1):
                    res[endY][i] = value
                    value += 1

            if endY > start + 1 and endX > start:
                for i in range(endY - 1, start, -1):
                    res[i][start] = value
                    value += 1

            start += 1

        return res
