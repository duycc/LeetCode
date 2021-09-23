/**
 * @file     topKFrequent3.cpp
 * @brief    https://leetcode-cn.com/problems/top-k-frequent-elements/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    std::unordered_map<int, int> elemFreq;
    for (auto num : nums) {
      elemFreq[num]++;
    }

    struct Comp {
    public:
      bool operator()(std::pair<int, int> &a, std::pair<int, int> &b) { return a.second > b.second; }
    };

    std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, Comp> priQue;
    for (auto &elem : elemFreq) {
      priQue.emplace(elem);
      if (priQue.size() > k) {
        priQue.pop();
      }
    }

    vector<int> result;
    while (!priQue.empty()) {
      result.emplace_back(priQue.top().first);
      priQue.pop();
    }
    return result;
  }
};
