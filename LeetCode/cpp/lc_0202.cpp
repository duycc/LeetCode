/**
 * @file     lc_0202.cpp
 * @brief    https://leetcode-cn.com/problems/happy-number/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  bool isHappy(int n) {
    std::unordered_set<int> sumSet;
    while (true) {
      int sum = getSum(n);
      if (1 == sum) {
        break;
      }
      if (sumSet.find(sum) != sumSet.end()) { // 重复出现，陷入死循环，退出
        return false;
      } else {
        sumSet.emplace(sum);
        n = sum;
      }
    }
    return true;
  }

private:
  int getSum(int n) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }
};
