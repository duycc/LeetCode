/**
 * @file     jz_005.cpp
 * @brief    https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  string replaceSpace(string s) {
    if (s.empty()) {
      return string();
    }
    std::string result;
    for (auto ch : s) {
      if (ch == ' ') {
        result += "%20";
      } else {
        result += ch;
      }
    }
    return result;
  }
};
