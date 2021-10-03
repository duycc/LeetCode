/**
 * @file     lc_0217.cpp
 * @brief    https://leetcode-cn.com/problems/contains-duplicate/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    if (nums.empty()) {
      return false;
    }
    std::unordered_set<int> exist;
    for (auto &num : nums) {
      if (exist.find(num) != exist.end()) {
        return true;
      }
      exist.emplace(num);
    }
    return false;
  }
};
