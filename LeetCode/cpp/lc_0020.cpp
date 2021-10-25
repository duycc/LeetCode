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
    for (auto ch : s) {
      if (ch == '[') {
        stk.push(']');
      } else if (ch == '(') {
        stk.push(')');
      } else if (ch == '{') {
        stk.push('}');
      } else if (stk.empty() || ch != stk.top()) {
        return false; // 先判断空，否则有可能top()解引用失败
      } else {
        stk.pop();
      }
    }
    return stk.empty();
  }
};
