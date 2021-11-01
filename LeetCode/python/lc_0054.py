"""
 * @file     lc_0054.py
 * @brief    https://leetcode-cn.com/problems/spiral-matrix/
 * @author   YongDu
 * @date     2021-11-01
"""


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        rows, cols = len(matrix), len(matrix[0])
        start = 0
        res = []

        while rows > 2 * start and cols > 2 * start:
            endX, endY = cols - 1 - start, rows - 1 - start

            for i in range(start, endX + 1):
                res.append(matrix[start][i])

            if endY > start:
                for i in range(start + 1, endY + 1):
                    res.append(matrix[i][endX])

            if endY > start and endX > start:
                for i in range(endX - 1, start - 1, -1):
                    res.append(matrix[endY][i])

            if endY > start + 1 and endX > start:
                for i in range(endY - 1, start, - 1):
                    res.append(matrix[i][start])

            start += 1

        return res
