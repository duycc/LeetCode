/**
 * @file     lc_0217.cpp
 * @brief    https://leetcode-cn.com/problems/contains-duplicate/
 * @author   YongDu
 * @date     2021-10-04
 */

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        return nums.size() != numSet.size();
    }
};
