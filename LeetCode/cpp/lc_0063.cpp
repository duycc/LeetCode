/**
 * @file     lc_0063.cpp
 * @brief    https://leetcode-cn.com/problems/unique-paths-ii/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty()) {
      return 0;
    }
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));

    for (int i = 0; i < row && obstacleGrid[i][0] == 0; ++i) {
      result[i][0] = 1;
    }
    for (int i = 0; i < col && obstacleGrid[0][i] == 0; ++i) {
      result[0][i] = 1;
    }

    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        if (obstacleGrid[i][j] != 1) {
          result[i][j] = result[i - 1][j] + result[i][j - 1];
        }
      }
    }
    return result[row - 1][col - 1];
  }
};
