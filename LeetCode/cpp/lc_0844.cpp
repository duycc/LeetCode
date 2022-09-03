/**
 * @file     lc_0844.cpp
 * @brief    https://leetcode-cn.com/problems/backspace-string-compare/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    bool backspaceCompare(string s, string t) {
        auto getText = [](string str) {
            string lastStr;
            for (auto ch : str) {
                if (ch != '#') {
                    lastStr.push_back(ch);
                } else if (!lastStr.empty()) {
                    lastStr.pop_back();
                }
            }
            return lastStr;
        };
        return getText(s) == getText(t);
    }
};