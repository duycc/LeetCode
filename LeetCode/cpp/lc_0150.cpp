/**
 * @file     lc_0150.cpp
 * @brief    https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 * @author   YongDu
 * @date     2021-09-10
 */
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    std::stack<int> operands;
    for (auto &token : tokens) {
      if ("+" == token || "-" == token || "*" == token || "/" == token) {
        int rhs = operands.top();
        operands.pop();
        int lhs = operands.top();
        operands.pop();

        if ("+" == token) {
          operands.push(lhs + rhs);
        } else if ("-" == token) {
          operands.push(lhs - rhs);
        } else if ("*" == token) {
          operands.push(lhs * rhs);
        } else {
          operands.push(lhs / rhs);
        }
      } else {
        operands.push(std::stoi(token));
      }
    }
    return operands.top();
  }
};
