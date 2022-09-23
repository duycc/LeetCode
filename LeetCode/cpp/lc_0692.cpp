/**
 * @file     lc_0692.cpp
 * @brief    https://leetcode-cn.com/problems/top-k-frequent-words/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
  public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> cntMap;
        for (auto& w : words) {
            cntMap[w]++;
        }
        auto comp = [](const std::pair<std::string, int>& lhs, const std::pair<std::string, int>& rhs) {
            return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
        };
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(comp)>
            priQue(comp);
        for (auto& elem : cntMap) {
            priQue.emplace(elem);
            if (priQue.size() > k) {
                priQue.pop();
            }
        }
        std::vector<std::string> result;
        while (!priQue.empty()) {
            result.insert(result.begin(), priQue.top().first);
            priQue.pop();
        }
        return result;
    }
};