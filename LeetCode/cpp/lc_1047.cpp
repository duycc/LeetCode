/**
 * @file     lc_1047.cpp
 * @brief    https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  string removeDuplicates(string s) {
    string res;
    for (auto &ch : s) {
      if (res.empty() || res.back() != ch) {
        res.push_back(ch);
      } else {
        res.pop_back();
      }
    }
    return res;
  }
};
