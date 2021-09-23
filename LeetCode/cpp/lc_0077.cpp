/**
 * @file     lc_0077.cpp
 * @brief    https://leetcode-cn.com/problems/combinations/
 * @author   YongDu
 * @date     2021-09-15
 */
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    backTrack(n, k, 1);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int>         path;

  void backTrack(int n, int k, int startIdx) {
    if (k == path.size()) {
      result.emplace_back(path);
      return;
    }
    for (int i = startIdx; i <= n - (k - path.size()) + 1; ++i) {
      path.emplace_back(i);
      backTrack(n, k, i + 1);
      path.pop_back();
    }
    return;
  }
};
