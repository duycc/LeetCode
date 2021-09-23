/**
 * @file     lc_0059.cpp
 * @brief    https://leetcode-cn.com/problems/spiral-matrix-ii/
 * @author   YongDu
 * @date     2021-09-07
 */
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));

    int start = 0;
    int value = 1;
    while (n > 2 * start) { // 采用[]区间填充
      int xEnd = n - 1 - start;
      int yEnd = n - 1 - start;

      for (int i = start; i <= xEnd; ++i) {
        result[start][i] = value++;
      }

      if (yEnd > start) {
        for (int i = start + 1; i <= yEnd; ++i) {
          result[i][xEnd] = value++;
        }
      }

      if (yEnd > start && xEnd > start) {
        for (int i = xEnd - 1; i >= start; --i) {
          result[yEnd][i] = value++;
        }
      }

      if (yEnd > start + 1 && xEnd > start) {
        for (int i = yEnd - 1; i > start; --i) {
          result[i][start] = value++;
        }
      }
      start++;
    }
    return result;
  }
};
