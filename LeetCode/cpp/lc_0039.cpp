/**
 * @file     lc_0039.cpp
 * @brief    https://leetcode-cn.com/problems/combination-sum/
 * @author   YongDu
 * @date     2021-09-15
 */
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    backtracking(candidates, target, 0, 0);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(vector<int> &candidates, int targetSum, int curSum, int beginIdx) {
    if (curSum > targetSum) {
      return;
    }
    if (curSum == targetSum) {
      result.emplace_back(path);
      return;
    }
    for (int i = beginIdx; i < candidates.size(); ++i) {
      path.emplace_back(candidates[i]);
      backtracking(candidates, targetSum, curSum + candidates[i], i);
      path.pop_back();
    }
  }
};
