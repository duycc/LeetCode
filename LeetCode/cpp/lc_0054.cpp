/**
 * @file     lc_0054.cpp
 * @brief    https://leetcode-cn.com/problems/spiral-matrix/
 * @author   YongDu
 * @date     2021-09-07
 */
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        while ((rows > 2 * start) && (cols > 2 * start)) {
            int xEnd = cols - 1 - start;
            int yEnd = rows - 1 - start;

            // 从左到右第一行
            for (int i = start; i <= xEnd; ++i) {
                result.emplace_back(matrix[start][i]);
            }
            // 从上到下一列
            if (start < yEnd) {
                for (int i = start + 1; i <= yEnd; ++i) {
                    result.emplace_back(matrix[i][xEnd]);
                }
            }
            // 从右到左一行
            if (xEnd > start && yEnd > start) {
                for (int i = xEnd - 1; i >= start; --i) {
                    result.emplace_back(matrix[yEnd][i]);
                }
            }
            // 从下到上一列
            if (xEnd > start && yEnd > start + 1) {
                for (int i = yEnd - 1; i > start; --i) {
                    result.emplace_back(matrix[i][start]);
                }
            }
            start++;
        }
        return result;
    }
};
