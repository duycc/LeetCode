/**
 * @file     isPowerOfThree.cpp
 * @brief    https://leetcode-cn.com/problems/power-of-three/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n < 1) {
      return false;
    }
    while (n % 3 == 0) {
      n /= 3;
    }
    return 1 == n;
  }
};
