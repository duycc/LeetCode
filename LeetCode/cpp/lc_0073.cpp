/**
 * @file     lc_0073.cpp
 * @brief    https://leetcode-cn.com/problems/set-matrix-zeroes/
 * @author   YongDu
 * @date     2021-10-14
 */

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<bool> rowFlg(rows, false);
        std::vector<bool> colFlg(cols, false);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    rowFlg[i] = true;
                    colFlg[j] = true;
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (rowFlg[i] || colFlg[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
