/**
 * @file     lc_0046.cpp
 * @brief    https://leetcode-cn.com/problems/permutations/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    if (nums.empty()) {
      return vector<vector<int>>();
    }
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(const vector<int> &nums, vector<bool> &used) {
    if (path.size() == nums.size()) {
      result.emplace_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) {
        continue;
      }
      used[i] = true;
      path.emplace_back(nums[i]);
      backtracking(nums, used);
      path.pop_back();
      used[i] = false;
    }
  }
};
