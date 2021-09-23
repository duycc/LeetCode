/**
 * @file     singleNumber.cpp
 * @brief    https://leetcode-cn.com/problems/single-number/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int single = 0;
    for (auto &&num : nums) {
      single ^= num;
    }
    return single;
  }
};
