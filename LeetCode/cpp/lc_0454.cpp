/**
 * @file     lc_0454.cpp
 * @brief    https://leetcode-cn.com/problems/4sum-ii/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
  public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int                          size = nums1.size();
        std::unordered_map<int, int> sumMap;
        for (int n1 : nums1) {
            for (int n2 : nums2) {
                sumMap[n1 + n2]++;
            }
        }
        int count{0};
        for (int n3 : nums3) {
            for (int n4 : nums4) {
                if (sumMap.find(0 - (n3 + n4)) != sumMap.end()) {
                    count += sumMap[0 - (n3 + n4)];
                }
            }
        }
        return count;
    }
};
