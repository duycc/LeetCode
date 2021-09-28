/**
 * @file     lc_0064.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-path-sum/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }

    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> result(row, vector<int>(col, INT_MAX));
    result[0][0] = grid[0][0];

    for (int i = 1; i < row; ++i) {
      result[i][0] = result[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < col; ++j) {
      result[0][j] = result[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        result[i][j] = std::min(result[i - 1][j], result[i][j - 1]) + grid[i][j];
      }
    }
    return result[row - 1][col - 1];
  }
};
