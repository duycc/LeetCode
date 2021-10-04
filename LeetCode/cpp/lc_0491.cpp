/**
 * @file     lc_0491.cpp
 * @brief    https://leetcode-cn.com/problems/increasing-subsequences/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    if (nums.empty()) {
      return vector<vector<int>>();
    }
    backtracking(nums, 0);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(const vector<int> &nums, int beginIdx) {
    if (path.size() > 1) {
      result.emplace_back(path);
    }
    std::unordered_set<int> used; // 不能排序去重，用set去重
    for (int i = beginIdx; i < nums.size(); ++i) {
      if (!path.empty() && nums[i] < path.back()) { // 入path之前就需要检测
        continue;
      }
      if (used.find(nums[i]) != used.end()) {
        continue;
      }
      used.emplace(nums[i]);
      path.emplace_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
};
