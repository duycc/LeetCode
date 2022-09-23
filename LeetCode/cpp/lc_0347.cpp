/**
 * @file     lc_0347.cpp
 * @brief    https://leetcode-cn.com/problems/top-k-frequent-elements/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> cntMap;
        for (int n : nums) {
            cntMap[n]++;
        }

        auto comp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> priQue(comp);
        for (auto& elem : cntMap) {
            priQue.emplace(elem);
            if (priQue.size() > k) {
                priQue.pop();
            }
        }

        std::vector<int> result;
        while (!priQue.empty()) {
            result.emplace_back(priQue.top().first);
            priQue.pop();
        }
        return result;
    }
};
