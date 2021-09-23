/**
 * @file     subsets.cpp
 * @brief    https://leetcode-cn.com/problems/subsets/
 * @author   YongDu
 * @date     2021-09-02
 */
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    backTrack(nums, 0);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> subset;

  void backTrack(vector<int> &nums, int startIndex) {
    result.emplace_back(subset);
    for (int i = startIndex; i < nums.size(); ++i) {
      subset.emplace_back(nums[i]);
      backTrack(nums, i + 1);
      subset.pop_back();
    }
    return;
  }
};
