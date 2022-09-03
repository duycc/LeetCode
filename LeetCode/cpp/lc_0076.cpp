/**
 * @file     lc_0076.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-window-substring/
 * @author   YongDu
 * @date     2021-09-07
 */
class Solution {
    using charMap = std::unordered_map<char, int>;

  public:
    string minWindow(string s, string t) {
        charMap dstMap;
        charMap curMap;

        for (auto& ch : t) {
            dstMap[ch]++;
        }

        int minLen = INT_MAX; // 最小长度
        int leftBound = -1;   // 最小长度左边界，最后截取子串
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            curMap[s[right]]++;
            while (isValidSubStr(curMap, dstMap) && left <= right) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    leftBound = left;
                }
                --curMap[s[left]];
                left++;
            }
        }
        return minLen == INT_MAX ? string{} : s.substr(leftBound, minLen);
    }

  private:
    bool isValidSubStr(charMap& curMap, charMap& dstMap) {
        for (auto& [ch, num] : dstMap) {
            if (curMap[ch] < num) {
                return false;
            }
        }
        return true;
    }
};
