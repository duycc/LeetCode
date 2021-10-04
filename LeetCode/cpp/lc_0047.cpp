/**
 * @file     lc_0047.cpp
 * @brief    https://leetcode-cn.com/problems/permutations-ii/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    if (nums.empty()) {
      return vector<vector<int>>();
    }
    std::sort(nums.begin(), nums.end());
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
      // 同层去重
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }
      if (used[i] == false) {
        used[i] = true;
        path.emplace_back(nums[i]);
        backtracking(nums, used);
        path.pop_back();
        used[i] = false;
      }
    }
  }
};
