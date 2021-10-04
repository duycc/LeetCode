/**
 * @file     lc_0077.cpp
 * @brief    https://leetcode-cn.com/problems/combinations/
 * @author   YongDu
 * @date     2021-09-15
 */
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    backTracking(n, k, 1);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> path;

  void backTracking(int n, int k, int beginIdx) {
    if (path.size() == k) {
      result.emplace_back(path);
      return;
    }
    for (int i = beginIdx; i <= n - (k - path.size()) + 1; ++i) {
      path.emplace_back(i);
      backTracking(n, k, i + 1);
      path.pop_back();
    }
  }
};
