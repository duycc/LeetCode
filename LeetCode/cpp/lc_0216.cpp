/**
 * @file     lc_0216.cpp
 * @brief    https://leetcode-cn.com/problems/combination-sum-iii/
 * @author   YongDu
 * @date     2021-09-15
 */
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(n, 0, k, 1);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(int targetSum, int curSum, int k, int beginIdx) {
    if (path.size() == k) {
      if (curSum == targetSum) {
        result.emplace_back(path);
      }
      return;
    }
    for (int i = beginIdx; i <= 9 - (k - path.size()) + 1; ++i) { // 剪枝优化
      path.emplace_back(i);
      backtracking(targetSum, curSum + i, k, i + 1);
      path.pop_back();
    }
  }
};
