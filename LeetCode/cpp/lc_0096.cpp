/**
 * @file     lc_0096.cpp
 * @brief    https://leetcode-cn.com/problems/unique-binary-search-trees/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
