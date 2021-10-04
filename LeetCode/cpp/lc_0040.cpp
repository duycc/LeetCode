/**
 * @file     lc_0040.cpp
 * @brief    https://leetcode-cn.com/problems/combination-sum-ii/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
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
      if (i > beginIdx && candidates[i] == candidates[i - 1]) {
        continue;
      }
      curSum += candidates[i];
      path.emplace_back(candidates[i]);
      backtracking(candidates, targetSum, curSum, i + 1);
      path.pop_back();
      curSum -= candidates[i];
    }
  }
};
