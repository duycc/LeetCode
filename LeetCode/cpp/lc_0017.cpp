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
      return result;
    }
    backTracking(digits, 0);
    return result;
  }

private:
  vector<string> result;
  string path;

  const vector<string> letterMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  void backTracking(const string &digits, int nthDigit) {
    if (nthDigit == digits.size()) {
      result.emplace_back(path);
      return;
    }
    int digit = digits[nthDigit] - '0';
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); ++i) {
      path.push_back(letters[i]);
      backTracking(digits, nthDigit + 1);
      path.pop_back();
    }
    return;
  }
};
