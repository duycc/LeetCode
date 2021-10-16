/**
 * @file     jz_003.cpp
 * @brief    https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    std::unordered_set<int> numSet;
    int val = 0;
    for (auto num : nums) {
      if (numSet.find(num) != numSet.end()) {
        val = num;
        break;
      }
      numSet.emplace(num);
    }
    return val;
  }
};
