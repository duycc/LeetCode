/**
 * @file     lc_0139.cpp
 * @brief    https://leetcode-cn.com/problems/word-break/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    std::unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> result(s.size() + 1, false);
    result[0] = true;

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        string word = s.substr(j, i - j);
        if (wordSet.find(word) != wordSet.end() && result[j]) {
          result[i] = true;
        }
      }
    }
    return result[s.size()];
  }
};
