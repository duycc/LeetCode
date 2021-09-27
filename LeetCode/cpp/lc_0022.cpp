/**
 * @file     lc_0022.cpp
 * @brief    https://leetcode-cn.com/problems/generate-parentheses/
 * @author   YongDu
 * @date     2021-09-27
 */
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n <= 0) {
      return result;
    }
    backTrack(path, 0, 0, n);
    return result;
  }

private:
  vector<string> result;
  string path;

  void backTrack(string &path, int left, int right, int n) {
    if (path.size() == 2 * n) {
      result.emplace_back(path);
      return;
    }
    if (left < n) {
      path.push_back('(');
      backTrack(path, left + 1, right, n);
      path.pop_back();
    }
    if (right < left) {
      path.push_back(')');
      backTrack(path, left, right + 1, n);
      path.pop_back();
    }
    return;
  }
};
