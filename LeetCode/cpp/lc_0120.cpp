/**
 * @file     lc_0120.cpp
 * @brief    https://leetcode-cn.com/problems/triangle/
 * @author   YongDu
 * @date     2021-09-29
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
      // 只用一维vector保存中间结果，前面存放上一层结果，所以需要从后往前更新数组
      for (int j = i; j >= 0; --j) {
        if (j == 0) {
          result[j] = result[j] + triangle[i][j];
        } else {
          result[j] = std::min(result[j], result[j - 1]) + triangle[i][j];
        }
      }
    }
    return *std::min_element(result.begin(), result.end());
  }
};
