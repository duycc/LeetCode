/**
 * @file     lc_0349.cpp
 * @brief    https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * @author   YongDu
 * @date     2021-09-08
 */

class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1st(nums1.begin(), nums1.end());
        std::unordered_set<int> resSet;
        for (int n : nums2) {
            if (set1st.find(n) != set1st.end()) {
                resSet.emplace(n);
            }
        }
        return std::vector(resSet.begin(), resSet.end());
    }
};
