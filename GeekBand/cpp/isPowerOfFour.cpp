/**
 * @file     isPowerOfFour.cpp
 * @brief    https://leetcode-cn.com/problems/power-of-four/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  bool isPowerOfFour(int n) { return n > 0 && (n & (n - 1)) == 0 && (n % 3) == 1; }
};
