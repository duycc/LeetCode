/**
 * @file     lc_0692.cpp
 * @brief    https://leetcode-cn.com/problems/top-k-frequent-words/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> hashMap; // 统计词频
    for (auto &word : words) {
      hashMap[word]++;
    }

    struct Comp {
      bool operator()(const pair<string, int> &lhs, const pair<string, int> &rhs) {
        return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
      }
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> priQue;

    for (auto &elem : hashMap) {
      priQue.emplace(elem);
      if (priQue.size() > k) {
        priQue.pop();
      }
    }

    vector<string> result;
    while (!priQue.empty()) {
      result.insert(result.begin(), priQue.top().first); // 采用 insert() 模拟栈
      priQue.pop();
    }

    return result;
  }
};
