/**
 * @file     lc_0151.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-words-in-a-string/
 * @author   YongDu
 * @date     2021-09-09
 */
class Solution {
public:
  string reverseWords(string s) {
    if (s.empty()) {
      return string();
    }
    removeExtraSpaces(s);
    reverse(s, 0, s.size() - 1);
    for (int i = 0; i < s.size(); ++i) {
      int j = i;
      while (j < s.size() && s[j] != ' ') {
        j++;
      }
      reverse(s, i, j - 1);
      i = j;
    }
    return s;
  }

private:
  void removeExtraSpaces(string &s) {
    if (s.empty()) {
      return;
    }
    int slow = 0, fast = 0;
    while (fast < s.size() && s[fast] == ' ') {
      fast++;
    }
    for (; fast < s.size(); ++fast) {
      if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
        continue;
      } else {
        s[slow++] = s[fast];
      }
    }
    if (slow - 1 > 0 && s[slow - 1] == ' ') { // 去掉末尾空格
      s.resize(slow - 1);
    } else {
      s.resize(slow);
    }
  }

  void reverse(string &s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      std::swap(s[i], s[j]);
    }
    return;
  }
};
