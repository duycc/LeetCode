/**
 * @file     lc_5902.cpp
 * @brief    https://leetcode-cn.com/problems/check-if-numbers-are-ascending-in-a-sentence/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [stringstream] -----------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  bool areNumbersAscending(string s) {
    int preVal = INT_MIN;
    int curVal = 0;
    std::stringstream sstr(s);
    string word;
    while (sstr >> word) {
      if (std::isdigit(word[0])) {
        curVal = std::stoi(word);
        if (curVal <= preVal) {
          return false;
        }
        preVal = curVal;
      }
    }
    return true;
  }
};
