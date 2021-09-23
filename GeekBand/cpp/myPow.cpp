/**
 * @file     myPow.cpp
 * @brief    https://leetcode-cn.com/problems/powx-n/
 * @author   YongDu
 * @date     2021-09-05
 */

// 迭代
class Solution {
public:
  double myPow(double x, int N) {
    long long n = N;
    return n >= 0 ? quickPow(x, n) : 1 / quickPow(x, -n);
  }

private:
  double quickPow(double x, long long n) {
    double result = 1;
    while (n > 0) {
      if (n % 2 == 1) {
        result *= x;
      }
      n /= 2;
      x *= x;
    }
    return result;
  }
};

// 递归
class Solution {
public:
  double myPow(double x, int N) {
    long long n = N;
    return n >= 0 ? quickPow(x, n) : 1.0 / quickPow(x, -n);
  }

private:
  double quickPow(double x, long long n) {
    if (0 == n) {
      return 1.0;
    }
    double y = quickPow(x, n / 2);
    return n % 2 == 0 ? y * y : y * y * x;
  }
};
