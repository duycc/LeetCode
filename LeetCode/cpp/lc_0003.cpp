/**
 * @file     lc_0003.cpp
 * @brief    https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * @author   YongDu
 * @date     2021-10-24
 */
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
        int maxLen = 0;
        for (int left = 0, right = 0; left < s.size(); ++left) {
            while (right < s.size() && charSet.find(s[right]) == charSet.end()) {
                charSet.emplace(s[right++]);
            }
            maxLen = std::max(maxLen, right - left);
            charSet.erase(s[left]);
        }
        return maxLen;
    }
};
