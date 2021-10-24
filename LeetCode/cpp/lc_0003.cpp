/**
 * @file     lc_0003.cpp
 * @brief    https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * @author   YongDu
 * @date     2021-10-24
 */
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    std::unordered_set<char> occ;
    int len = s.size();
    int maxLen = 0;
    int right = 0;
    for (int left = 0; left < len; ++left) {
      if (left != 0) {
        occ.erase(s[left - 1]);
      }
      while (right < len && occ.find(s[right]) == occ.end()) {
        occ.emplace(s[right++]);
      }
      maxLen = std::max(maxLen, right - left);
    }
    return maxLen;
  }
};
