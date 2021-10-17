/**
 * @file     lc_0860.cpp
 * @brief    https://leetcode-cn.com/problems/lemonade-change/
 * @author   YongDu
 * @date     2021-10-17
 */
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int five = 0;
    int ten = 0;
    // int twenty = 0;
    for (int bill : bills) {
      if (bill == 5) {
        five++;
      }
      if (bill == 10) {
        if (five <= 0) {
          return false;
        }
        five--;
        ten++;
      }
      if (bill == 20) {
        if (ten > 0 && five > 0) {
          ten--;
          five--;
          // twenty++;
        } else if (ten <= 0 && five >= 3) {
          five -= 3;
          // twenty++;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
