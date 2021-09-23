/**
 * @file     minimumTotal.cpp
 * @brief    https://leetcode-cn.com/problems/triangle/
 * @author   YongDu
 * @date     2021-08-15
 */
class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.empty()) {
      return 0;
    }
    int row = triangle.size();
    vector<int> result(row, INT_MAX);
    result[0] = triangle[0][0];
    for (int i = 1; i < row; ++i) {
      // 只有一层结果，注意从后往前更新结果集
      for (int j = i; j >= 0; --j) {
        if (0 == j) {
          result[j] = result[j] + triangle[i][j];
        } else {
          result[j] = std::min(result[j], result[j - 1]) + triangle[i][j];
        }
      }
    }

    return *std::min_element(result.begin(), result.end());
  }
};
