/**
 * @file     lc_0150.cpp
 * @brief    https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 * @author   YongDu
 * @date     2021-09-10
 */
class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int64_t> stk;
        for (string& tk : tokens) {
            if (tk == "+" || tk == "-" || tk == "*" || tk == "/") {
                int64_t rhs = stk.top();
                stk.pop();
                int64_t lhs = stk.top();
                stk.pop();
                if (tk == "+") {
                    stk.push(lhs + rhs);
                } else if (tk == "-") {
                    stk.push(lhs - rhs);
                } else if (tk == "*") {
                    stk.push(lhs * rhs);
                } else {
                    stk.push(lhs / rhs);
                }
            } else {
                stk.push(std::stoi(tk));
            }
        }
        return stk.top();
    }
};
