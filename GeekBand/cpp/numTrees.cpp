/**
 * @file     numTrees.cpp
 * @brief    https://leetcode-cn.com/problems/unique-binary-search-trees/
 * @author   YongDu
 * @date     2021-08-15
 */
class Solution {
public:
  int numTrees(int n) {
    vector<int> result(n + 1, 0);
    result[0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        result[i] += result[j - 1] * result[i - j];
      }
    }
    return result[n];
  }
};
