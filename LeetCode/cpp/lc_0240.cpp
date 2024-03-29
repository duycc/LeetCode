/**
 * @file     lc_0240.cpp
 * @brief    https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty())
      return false;

    int row = 0;
    int col = matrix[0].size() - 1;

    while (row < matrix.size() && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] > target) {
        col--;
      } else {
        row++;
      }
    }

    return false;
  }
};
