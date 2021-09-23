/**
 * @file     lc_0454.cpp
 * @brief    https://leetcode-cn.com/problems/4sum-ii/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    std::unordered_map<int, int> sumABMap; // <A[i] + B[i], count>
    for (int a : nums1) {
      for (int b : nums2) {
        sumABMap[a + b]++;
      }
    }
    int count = 0;
    for (int c : nums3) {
      for (int d : nums4) {
        if (sumABMap.find(0 - (c + d)) != sumABMap.end()) {
          count += sumABMap[0 - (c + d)];
        }
      }
    }
    return count;
  }
};
