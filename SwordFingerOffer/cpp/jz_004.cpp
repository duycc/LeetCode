/**
 * @file     jz_004.cpp
 * @brief    https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 * @author   YongDu
 * @date     2021-10-16
 */
class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty() || target < matrix[0][0] ||
        target > matrix[matrix.size() - 1][matrix[0].size() - 1]) {
      return false;
    }
    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] < target) {
        row++;
      } else {
        col--;
      }
    }
    return false;
  }
};
