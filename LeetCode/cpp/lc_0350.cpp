/**
 * @file     lc_0350.cpp
 * @brief    https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int>             result;
        std::unordered_map<int, int> exist;
        for (int n : nums1) {
            exist[n]++;
        }
        for (int n : nums2) {
            if (exist[n]) {
                result.push_back(n);
                exist[n]--;
            }
        }
        return result;
    }
};