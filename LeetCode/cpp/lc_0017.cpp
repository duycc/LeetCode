/**
 * @file     lc_0017.cpp
 * @brief    https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return vector<string>();
    }
    backtracking(digits, 0);
    return result;
  }

private:
  vector<string> result;
  string path;

  const vector<string> lettersMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  void backtracking(const string &digits, int index) {
    if (path.size() == digits.size()) {
      result.emplace_back(path);
      return;
    }
    int digit = digits[index] - '0';
    for (auto ch : lettersMap[digit]) {
      path.push_back(ch);
      backtracking(digits, index + 1);
      path.pop_back();
    }
  }
};
