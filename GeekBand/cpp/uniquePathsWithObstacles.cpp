/**
 * @file     uniquePathsWithObstacles.cpp
 * @brief    https://leetcode-cn.com/problems/unique-paths-ii/
 * @author   YongDu
 * @date     2021-08-15
 */
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    vector<vector<int>> result(row, vector<int>(col, 0)); // dp数组

    // 初始化边界
    for (int i = 0; i < row && obstacleGrid[i][0] == 0; ++i)
      result[i][0] = 1;
    for (int j = 0; j < col && obstacleGrid[0][j] == 0; ++j)
      result[0][j] = 1;
    // 求解
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
