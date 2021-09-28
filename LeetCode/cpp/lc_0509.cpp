/**
 * @file     lc_0509.cpp
 * @brief    https://leetcode-cn.com/problems/fibonacci-number/
 * @author   YongDu
 * @date     2021-09-28
 */
class Solution {
public:
  int fib(int n) {
    // 递归
    if (n == 0 || n == 1) {
      return n;
    }
    return fib(n - 1) + fib(n - 2);
  }
};

class Solution {
public:
  int fib(int n) {
    // dp
    if (n == 0 || n == 1) {
      return n;
    }

    int first = 0;
    int second = 1;
    int fibN = 0;

    for (int i = 2; i <= n; ++i) {
      fibN = first + second;
      first = second;
      second = fibN;
    }
    return fibN;
  }
};
