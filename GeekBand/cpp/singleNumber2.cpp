/**
 * @file     singleNumber2.cpp
 * @brief    https://leetcode-cn.com/problems/single-number-ii/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    std::unordered_map<int, int> hashMap;
    for (auto &num : nums) {
      hashMap[num]++;
    }
    for (auto &[num, freq] : hashMap) {
      if (freq == 1) {
        return num;
      }
    }
    return 0;
  }
};
