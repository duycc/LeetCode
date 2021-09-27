/**
 * @file     lc_0090.cpp
 * @brief    https://leetcode-cn.com/problems/subsets-ii/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    backTrack(nums, 0);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> subset;

  void backTrack(vector<int> &nums, int startIndex) {
    result.emplace_back(subset);
    std::unordered_set<int> uset;
    for (int i = startIndex; i < nums.size(); ++i) {
      if (uset.find(nums[i]) == uset.end()) {
        uset.emplace(nums[i]);
        subset.emplace_back(nums[i]);
        backTrack(nums, i + 1);
        subset.pop_back();
      }
    }
    return;
  }
};
