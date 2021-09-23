/**
 * @file     singleNumber3.cpp
 * @brief    https://leetcode-cn.com/problems/single-number-iii/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    std::unordered_map<int, int> hashMap;
    vector<int> result;
    for (auto &num : nums) {
      hashMap[num]++;
    }
    for (auto &[num, freq] : hashMap) {
      if (1 == freq) {
        result.emplace_back(num);
      }
    }
    return result;
  }
};
