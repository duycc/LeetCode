/**
 * @file     partitionPalindrome.cpp
 * @brief    https://leetcode-cn.com/problems/palindrome-partitioning/
 * @author   YongDu
 * @date     2021-08-11
 */
class Solution {
public:
  vector<vector<string>> partition(string s) {
    backTracking(s, 0);
    return result;
  }

private:
  vector<string> path;
  vector<vector<string>> result;
  /**
   * @brief 回溯函数
   *
   * @param s 切割的字符串
   * @param startIndex 切割线
   */
  void backTracking(const string &s, int startIndex) {
    if (startIndex >= s.size()) {
      result.emplace_back(path);
      return;
    }
    for (int i = startIndex; i < s.size(); ++i) {
      if (isPalindrome(s, startIndex, i)) {
        string str = s.substr(startIndex, i - startIndex + 1);
        path.emplace_back(str);
        backTracking(s, i + 1);
        path.pop_back();
      }
    }
    return;
  }
  /**
   * @brief 判断是否为回文串
   *
   * @param s
   * @param start
   * @param end
   * @return true
   * @return false
   */
  bool isPalindrome(const string &s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};
