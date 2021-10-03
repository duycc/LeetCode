/**
 * @file     lc_0482.cpp
 * @brief    https://leetcode-cn.com/problems/license-key-formatting/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    if (s.empty()) {
      return string();
    }
    string result;
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] != '-') {
        result.push_back(std::toupper(s[i]));
        cnt++;
        if (cnt % k == 0) {
          result.push_back('-');
        }
      }
    }
    if (result.back() == '-') {
      result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
