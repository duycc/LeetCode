/**
 * @file     subarraySum.cpp
 * @brief    https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    std::unordered_map<int, int> hashMap;
    hashMap[0] = 1;
    int count = 0;
    int pre = 0;
    for (auto &num : nums) {
      pre += num;
      if (hashMap.find(pre - k) != hashMap.end()) {
        count += hashMap[pre - k];
      }
      hashMap[pre]++;
    }
    return count;
  }
};
