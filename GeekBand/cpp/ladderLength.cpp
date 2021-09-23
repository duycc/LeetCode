/**
 * @file     ladderLength.cpp
 * @brief    https://leetcode-cn.com/problems/word-ladder/
 * @author   YongDu
 * @date     2021-09-02
 */
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    std::unordered_set<string> wordSet(wordList.begin(), wordList.end());

    if (wordSet.find(endWord) == wordSet.end()) {
      return 0;
    }

    std::unordered_map<string, int> visitMap; // <word, 查询到此 word 路径长度>
    std::queue<string> que;
    que.push(beginWord);
    visitMap.emplace(std::make_pair(beginWord, 1));

    while (!que.empty()) {
      string word = que.front();
      que.pop();
      int pathLen = visitMap[word];
      for (int i = 0; i < word.size(); ++i) {
        string newWord = word;
        for (int j = 0; j < 26; ++j) {
          newWord[i] = j + 'a'; // 必须是 'a' ?
          if (newWord == endWord) {
            return pathLen + 1;
          }
          if (wordSet.find(newWord) != wordSet.end() && visitMap.find(newWord) == visitMap.end()) {
            visitMap.emplace(std::make_pair(newWord, pathLen + 1));
            que.push(newWord);
          }
        }
      }
    }
    return 0;
  }
};
