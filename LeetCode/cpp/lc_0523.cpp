/**
 * @file     lc_0523.cpp
 * @brief    https://leetcode-cn.com/problems/continuous-subarray-sum/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    if (nums.size() < 2) {
      return false;
    }
    std::unordered_map<int, int> hashMap;
    hashMap[0] = -1;
    int remainder = 0;
    for (int i = 0; i < nums.size(); ++i) {
      remainder = (remainder + nums[i]) % k;
      if (hashMap.find(remainder) != hashMap.end()) {
        if (i - hashMap[remainder] >= 2) {
          return true;
        }
      } else {
        hashMap[remainder] = i;
      }
    }
    return false;
  }
};
