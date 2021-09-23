/**
 * @file     majorityElement2.cpp
 * @brief    https://leetcode-cn.com/problems/majority-element-ii/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    std::unordered_map<int, int> hashMap;
    std::unordered_set<int> majorities;
    for (auto &num : nums) {
      hashMap[num]++;
      if (hashMap[num] > nums.size() / 3) {
        majorities.emplace(num);
      }
    }
    return vector<int>(majorities.begin(), majorities.end());
  }
};
