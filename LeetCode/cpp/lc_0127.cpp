/**
 * @file     lc_0127.cpp
 * @brief    https://leetcode-cn.com/problems/word-ladder/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    // 广度优先遍历搜索最短路径
    std::unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) {
      // 不存在endWord
      return 0;
    }
    std::unordered_map<string, int> visitMap; // <word, 到此word路径长度>
    std::queue<string> que;
    que.push(beginWord);
    visitMap.insert(std::make_pair(beginWord, 1));

    while (!que.empty()) {
      string preWord = que.front();
      que.pop();
      int preLen = visitMap[preWord];
      for (int i = 0; i < preWord.size(); ++i) {
        string curWord = preWord;
        for (int j = 0; j < 26; ++j) {
          curWord[i] = 'a' + j;
          if (curWord == endWord) {
            return preLen + 1;
          }
          if (wordSet.find(curWord) != wordSet.end() && visitMap.find(curWord) == visitMap.end()) {
            visitMap[curWord] = preLen + 1;
            que.push(curWord);
          }
        }
      }
    }

    return 0;
  }
};
