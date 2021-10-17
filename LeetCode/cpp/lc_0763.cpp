/**
 * @file     lc_0763.cpp
 * @brief    https://leetcode-cn.com/problems/partition-labels/
 * @author   YongDu
 * @date     2021-10-17
 */
class Solution {
public:
  vector<int> partitionLabels(string s) {
    std::unordered_map<char, int> hashMap;
    for (int i = 0; i < s.size(); ++i) {
      hashMap[s[i]] = i;
    }
    vector<int> result;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.size(); ++i) {
      right = std::max(hashMap[s[i]], right);
      if (i == right) {
        result.emplace_back(right - left + 1);
        left = i + 1;
      }
    }
    return result;
  }
};
