/**
 * @file     jz_029.cpp
 * @brief    https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
 * @author   YongDu
 * @date     2021-09-07
 */
class Solution { /* DuYong 2020-10-14 */
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> result;
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return result;
    }

    int rows = matrix.size();
    int columns = matrix[0].size();

    int start = 0;
    while ((rows > 2 * start) && (columns > 2 * start)) {
      int endX = columns - 1 - start;
      int endY = rows - 1 - start;

      // 1. 从左到右打印第一行
      for (int i = start; i <= endX; i++) {
        result.push_back(matrix[start][i]);
      }

      // 2. 从上到下打印一列
      if (start < endY) {
        for (int i = start + 1; i <= endY; i++) {
          result.push_back(matrix[i][endX]);
        }
      }

      // 3. 从右到左打印一行
      if (start < endY && start < endX) {
        for (int i = endX - 1; i >= start; i--) {
          result.push_back(matrix[endY][i]);
        }
      }

      // 4. 从下到上打印一列
      if (start < endX && start < endY - 1) {
        for (int i = endY - 1; i > start; i--) {
          result.push_back(matrix[i][start]);
        }
      }
      start++;
    }
    return result;
  }
};
