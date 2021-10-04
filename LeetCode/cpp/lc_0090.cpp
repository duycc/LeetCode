/**
 * @file     lc_0090.cpp
 * @brief    https://leetcode-cn.com/problems/subsets-ii/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    if (nums.empty()) {
      return vector<vector<int>>();
    }
    std::sort(nums.begin(), nums.end());
    backtracking(nums, 0);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(const vector<int> &nums, int beginIdx) {
    result.emplace_back(path);
    for (int i = beginIdx; i < nums.size(); ++i) {
      if (i > beginIdx && nums[i] == nums[i - 1]) {
        continue;
      }
      path.emplace_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
};
