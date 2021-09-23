/**
 * @file     longestCommonSubsequence.cpp
 * @brief    https://leetcode-cn.com/problems/longest-common-subsequence/
 * @author   YongDu
 * @date     2021-08-31
 */
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> result(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          result[i][j] = result[i - 1][j - 1] + 1;
        } else {
          result[i][j] = std::max(result[i - 1][j], result[i][j - 1]);
        }
      }
    }
    return result[m][n];
  }
};
