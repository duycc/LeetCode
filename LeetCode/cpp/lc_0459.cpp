/**
 * @file     lc_0459.cpp
 * @brief    https://leetcode-cn.com/problems/repeated-substring-pattern/
 * @author   YongDu
 * @date     2021-10-02
 */
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    if (s.empty()) {
      return false;
    }
    int len = s.size();
    vector<int> next(len, 0);
    getNext(s, next);
    return (next[len - 1] != 0) && (len % (len - next[len - 1]) == 0);
  }

private:
  void getNext(const string &s, vector<int> &next) {
    int j = 0;
    for (int i = 1; i < s.size(); ++i) {
      while (j > 0 && s[i] != s[j]) {
        j = next[j - 1];
      }
      if (s[i] == s[j]) {
        j++;
      }
      next[i] = j;
    }
  }
};
