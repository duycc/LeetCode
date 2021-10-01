/**
 * @file     lc_0028.cpp
 * @brief    https://leetcode-cn.com/problems/implement-strstr/
 * @author   YongDu
 * @date     2021-10-01
 */
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) {
      return 0;
    }
    vector<int> next(needle.size(), 0);
    getNext(needle, next);
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == needle.size()) {
        return (i - needle.size() + 1);
      }
    }
    return -1;
  }

private:
  void getNext(const string &needle, vector<int> &next) {
    int j = 0;
    for (int i = 1; i < needle.size(); ++i) {
      while (j > 0 && needle[i] != needle[j]) {
        j = next[j - 1];
      }
      if (needle[i] == needle[j]) {
        j++;
      }
      next[i] = j;
    }
    return;
  }
};
