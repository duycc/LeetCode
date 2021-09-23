/**
 * @file     letterCombinations.cpp
 * @brief    https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
 * @author   YongDu
 * @date     2021-08-10
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
  string str;

  vector<string> letterMap{
      "",     // 0
      "",     // 1
      "abc",  // 2
      "def",  // 3
      "ghi",  // 4
      "jkl",  // 5
      "mno",  // 6
      "pqrs", // 7
      "tuv",  // 8
      "wxyz"  // 9
  };
  void backTracking(const string &digits, int index) {
    if (digits.size() == index) {
      result.emplace_back(str);
      return;
    }
    int digit = digits[index] - '0';
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); ++i) {
      str.push_back(letters[i]);
      backTracking(digits, index + 1);
      str.pop_back();
    }
    return;
  }
};
