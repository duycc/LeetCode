/**
 * @file     lc_0151.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-words-in-a-string/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
  public:
    string reverseWords(string s) {
        std::stringstream ss(s);
        std::string result;
        std::stack<std::string> stk;
        while (ss >> result) {
            stk.push(result);
        }
        result.clear();
        while (!stk.empty()) {
            result += stk.top() + " ";
            stk.pop();
        }
        result.pop_back();
        return result;
    }
};
