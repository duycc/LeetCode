/**
 * @file     isPowerOfTwo.cpp
 * @brief    https://leetcode-cn.com/problems/power-of-two/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};
