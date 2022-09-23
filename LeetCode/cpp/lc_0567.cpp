/**
 * @file     lc_0567.cpp
 * @brief    https://leetcode-cn.com/problems/permutation-in-string/
 * @author   YongDu
 * @date     2021-10-24
 */

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (n < m) {
            return false;
        }
        std::vector<int> cnt1(26);
        std::vector<int> cnt2(26);
        for (int i = 0; i < m; ++i) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = m; i < n; ++i) {
            cnt2[s2[i] - 'a']++;
            cnt2[s2[i - m] - 'a']--;
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};
