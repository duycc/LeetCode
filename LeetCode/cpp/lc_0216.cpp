/**
 * @file     lc_0216.cpp
 * @brief    https://leetcode-cn.com/problems/combination-sum-iii/
 * @author   YongDu
 * @date     2021-09-15
 */
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    backTrack(k, n, 0, 1);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int>         path;

  void backTrack(int k, int target, int sum, int startIdx) {
    if (sum > target) {
      return;
    }
    if (path.size() == k) {
      if (sum == target) {
        result.emplace_back(path);
      }
      return;
    }
    for (int i = startIdx; i <= 9; ++i) {
      path.emplace_back(i);
      backTrack(k, target, sum + i, i + 1);
      path.pop_back();
    }
    return;
  }
};
