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
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows && obstacleGrid[i][0] == 0; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 0; i < cols && obstacleGrid[0][i] == 0; ++i) {
      dp[0][i] = 1;
    }

    for (int i = 1; i < rows; ++i) {
      for (int j = 1; j < cols; ++j) {
        if (obstacleGrid[i][j] != 1) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
    }
    return dp[rows - 1][cols - 1];
  }
};
