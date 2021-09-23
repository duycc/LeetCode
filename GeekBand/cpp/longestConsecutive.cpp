/**
 * @file     longestConsecutive.cpp
 * @brief    https://leetcode-cn.com/problems/longest-consecutive-sequence/
 * @author   YongDu
 * @date     2021-08-18
 */

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    std::unordered_set<int> hashTab{nums.begin(), nums.end()};
    int maxLen{0};
    for (auto num : hashTab) {
      if (hashTab.count(num - 1)) {
        continue;
      }
      int start = num;
      while (hashTab.count(++start)) {
      }
      maxLen = std::max(maxLen, start - num);
    }
    return maxLen;
  }
};
