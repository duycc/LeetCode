/**
 * @file     generateParenthesis.cpp
 * @brief    https://leetcode-cn.com/problems/generate-parentheses/
 * @author   YongDu
 * @date     2021-09-02
 */
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    backTrack(current, 0, 0, n);
    return result;
  }

private:
  vector<string> result;
  string current;

  void backTrack(string &current, int left, int right, int n) {
    if (current.size() == 2 * n) {
      result.emplace_back(current);
      return;
    }
    if (left < n) {
      current.push_back('(');
      backTrack(current, left + 1, right, n);
      current.pop_back();
    }
    if (right < left) {
      current.push_back(')');
      backTrack(current, left, right + 1, n);
      current.pop_back();
    }
    return;
  }
};
