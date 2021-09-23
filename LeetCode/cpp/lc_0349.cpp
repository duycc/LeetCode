/**
 * @file     lc_0349.cpp
 * @brief    https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    if (nums1.empty() || nums2.empty()) {
      return result;
    }
    std::unordered_set<int> s1{nums1.begin(), nums1.end()};
    for (auto num : nums2) {
      if (s1.find(num) != s1.end()) {
        result.emplace_back(num);
        s1.erase(num);
      }
    }
    return result;
  }
};
