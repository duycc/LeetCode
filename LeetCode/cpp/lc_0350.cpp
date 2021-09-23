/**
 * @file     lc_0350.cpp
 * @brief    https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    unordered_map<int, int> exist;

    for (auto &num : nums1) {
      exist[num]++;
    }

    for (auto &num : nums2) {
      if (exist[num]) {
        result.emplace_back(num);
        exist[num]--;
      }
    }

    return result;
  }
};
