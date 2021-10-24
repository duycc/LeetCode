/**
 * @file     lc_0474.cpp
 * @brief    https://leetcode-cn.com/problems/ones-and-zeroes/
 * @author   YongDu
 * @date     2021-10-24
 */
class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string str : strs) {
      int oneNum = 0;
      int zeroNum = 0;
      for (char ch : str) {
        if (ch == '0') {
          zeroNum++;
        } else {
          oneNum++;
        }
      }
      for (int i = m; i >= zeroNum; --i) {
        for (int j = n; j >= oneNum; --j) {
          dp[i][j] = std::max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
