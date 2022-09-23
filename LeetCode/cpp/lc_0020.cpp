/**
 * @file     lc_0020.cpp
 * @brief    https://leetcode-cn.com/problems/valid-parentheses/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
  public:
    bool isValid(string s) {
        std::stack<char> stk;
        for (char ch : s) {
            if (ch == '(') {
                stk.push(')');
            } else if (ch == '[') {
                stk.push(']');
            } else if (ch == '{') {
                stk.push('}');
            } else if (stk.empty() || ch != stk.top()) {
                return false;
            } else {
                stk.pop();
            }
        }
        return stk.empty();
    }
};
