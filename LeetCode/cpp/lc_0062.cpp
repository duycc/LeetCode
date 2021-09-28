/**
 * @file     lc_0062.cpp
 * @brief    https://leetcode-cn.com/problems/unique-paths/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> result(m, vector<int>(n, 0));
    for (int row = 0; row < m; ++row) {
      for (int col = 0; col < n; ++col) {
        if (row == 0 || col == 0) {
          result[row][col] = 1;
        } else {
          result[row][col] = result[row - 1][col] + result[row][col - 1];
        }
      }
    }
    return result[m - 1][n - 1];
  }
};
