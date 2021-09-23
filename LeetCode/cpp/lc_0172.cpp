/**
 * @file     lc_0172.cpp
 * @brief    https://leetcode-cn.com/problems/factorial-trailing-zeroes/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int trailingZeroes(int n) {
    int count = 0;
    while (n) {
      count += n / 5;
      n /= 5;
    }
    return count;
  }
};
