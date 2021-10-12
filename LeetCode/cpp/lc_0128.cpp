/**
 * @file     lc_0128.cpp
 * @brief    https://leetcode-cn.com/problems/longest-consecutive-sequence/
 * @author   YongDu
 * @date     2021-08-18
 */

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLen = 0;
    for (auto num : numSet) {
      if (numSet.find(num - 1) != numSet.end()) {
        continue; // 跳过已经检查过的元素
      }
      int start = num;
      while (numSet.find(start) != numSet.end()) {
        start++;
      }
      maxLen = std::max(start - num, maxLen);
    }
    return maxLen;
  }
};
