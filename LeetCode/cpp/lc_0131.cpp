/**
 * @file     lc_0131.cpp
 * @brief    https://leetcode-cn.com/problems/palindrome-partitioning/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  vector<vector<string>> partition(string s) {
    if (s.empty()) {
      return result;
    }
    backTracking(s, 0);
    return result;
  }

private:
  vector<vector<string>> result;
  vector<string> path;

  void backTracking(const string &s, int begin) {
    if (begin == s.size()) {
      result.emplace_back(path);
      return;
    }
    for (int i = begin; i < s.size(); ++i) {
      if (isPalindrome(s, begin, i)) {
        string str = s.substr(begin, i - begin + 1);
        path.emplace_back(str);
        backTracking(s, i + 1);
        path.pop_back();
      }
    }
    return;
  }

  bool isPalindrome(const string &s, int begin, int end) {
    for (int i = begin, j = end; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};
