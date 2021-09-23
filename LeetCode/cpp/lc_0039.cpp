/**
 * @file     lc_0039.cpp
 * @brief    https://leetcode-cn.com/problems/combination-sum/
 * @author   YongDu
 * @date     2021-09-15
 */
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    backTrack(candidates, target, 0, 0);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int>         path;

  void backTrack(vector<int> &candidates, int target, int sum, int startIdx) {
    if (sum > target) {
      return;
    }
    if (sum == target) {
      result.emplace_back(path);
      return;
    }
    for (int i = startIdx; i < candidates.size(); ++i) {
      sum += candidates[i];
      path.emplace_back(candidates[i]);
      backTrack(candidates, target, sum, i);
      path.pop_back();
      sum -= candidates[i];
    }
    return;
  }
};
