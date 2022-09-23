/**
 * @file     lc_1047.cpp
 * @brief    https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
  public:
    string removeDuplicates(string s) {
        std::string result;
        for (char ch : s) {
            if (ch == result.back()) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};
