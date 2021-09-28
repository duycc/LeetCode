/**
 * @file     lc_0140.cpp
 * @brief    https://leetcode-cn.com/problems/word-break-ii/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    // 回溯 + 记忆化搜索
    wordSet = std::unordered_set(wordDict.begin(), wordDict.end());
    backTrack(s, 0);
    return result[0];
  }

private:
  std::unordered_set<string> wordSet;
  std::unordered_map<int, vector<string>> result;

  void backTrack(const string &s, int index) {
    if (index == s.size()) {
      result[index] = {""};
      return;
    }
    result[index] = {};
    for (int i = index + 1; i <= s.size(); ++i) {
      string word = s.substr(index, i - index);
      if (wordSet.count(word)) {
        backTrack(s, i);
        for (auto &sentence : result[i]) {
          result[index].emplace_back(sentence.empty() ? word : word + ' ' + sentence);
        }
      }
    }
    return;
  }
};
