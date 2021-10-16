/**
 * @file     jz_011.cpp
 * @brief    https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 * @author   YongDu
 * @date     2021-10-16
 */
class Solution {
public:
  int minArray(vector<int> &numbers) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
      int mid = left + ((right - left) >> 1);
      if (numbers[mid] > numbers[right]) {
        left = mid + 1;
      } else if (numbers[mid] < numbers[right]) {
        right = mid;
      } else {
        right--;
      }
    }
    return numbers[left];
  }
};
