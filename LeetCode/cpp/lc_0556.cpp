/**
 * @file     lc_0556.cpp
 * @brief    https://leetcode-cn.com/problems/next-greater-element-iii/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int nextGreaterElement(int n) {
    string str = std::to_string(n);
    int len = str.size();
    if (1 == len) { // 只有一位数字，必然找不到
      return -1;
    }
    int i = [&] {
      for (int k = len - 1; k > 0; --k) {
        if (str[k - 1] < str[k]) {
          return k - 1;
        }
      }
      return -1;
    }();
    if (-1 == i) { // 递减字符串，必然找不到
      return -1;
    }

    int j = [&] { // 待交换元素
      for (int k = len - 1; k > i; --k) {
        if (str[k] > str[i]) {
          return k;
        }
      }
      return -1;
    }();
    std::swap(str[i], str[j]);                    // 交换元素
    std::reverse(str.begin() + i + 1, str.end()); // 缩小数值
    long long res = std::stol(str);
    return res > INT32_MAX ? -1 : res;
  }
};
