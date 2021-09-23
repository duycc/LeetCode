/**
 * @file     lc_0020.cpp
 * @brief    https://leetcode-cn.com/problems/valid-parentheses/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  bool isValid(string s) {
    std::stack<int> brackets;
    for (auto &brace : s) {
      if ('(' == brace) {
        brackets.push(')');
      } else if ('{' == brace) {
        brackets.push('}');
      } else if ('[' == brace) {
        brackets.push(']');
      } else if (brackets.empty() || brackets.top() != brace) {
        return false;
      } else {
        brackets.pop();
      }
    }
    return brackets.empty();
  }
};
