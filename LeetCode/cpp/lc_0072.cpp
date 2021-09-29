/**
 * @file     lc_0072.cpp
 * @brief    https://leetcode-cn.com/problems/edit-distance/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  int minDistance(string word1, string word2) {
    size_t m = word1.size(), n = word2.size();
    vector<vector<int>> result(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 0; i <= m; ++i) {
      result[i][0] = i;
    }
    for (size_t j = 0; j <= n; ++j) {
      result[0][j] = j;
    }

    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          result[i][j] = result[i - 1][j - 1];
        } else {
          result[i][j] = std::min({result[i - 1][j], result[i][j - 1], result[i - 1][j - 1]}) + 1;
        }
      }
    }
    return result[m][n];
  }
};
