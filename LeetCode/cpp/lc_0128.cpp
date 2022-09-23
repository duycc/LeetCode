/**
 * @file     lc_0128.cpp
 * @brief    https://leetcode-cn.com/problems/longest-consecutive-sequence/
 * @author   YongDu
 * @date     2021-08-18
 */
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;

        std::unordered_set<int> numSet(nums.begin(), nums.end());
        for (int n : numSet) {
            if (numSet.find(n - 1) != numSet.end()) {
                continue;
            }
            int start = n;
            while (numSet.find(start) != numSet.end()) {
                start++;
            }
            maxLen = std::max(maxLen, start - n);
        }
        return maxLen;
    }
};
