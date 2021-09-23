/**
 * @file     lc_0941.cpp
 * @brief    https://leetcode-cn.com/problems/valid-mountain-array/
 * @author   YongDu
 * @date     2021-09-10
 */
class Solution {
public:
  bool validMountainArray(vector<int> &arr) {
    if (arr.size() < 3) {
      return false;
    }
    int left = 0, right = arr.size() - 1;
    while (left < arr.size() - 1 && arr[left] < arr[left + 1]) {
      left++;
    }
    while (right > 0 && arr[right] < arr[right - 1]) {
      right--;
    }
    return left == right && left != 0 && right != arr.size() - 1;
  }
};
