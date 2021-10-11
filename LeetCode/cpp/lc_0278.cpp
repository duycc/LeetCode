/**
 * @file     lc_0278.cpp
 * @brief    https://leetcode-cn.com/problems/first-bad-version/
 * @author   YongDu
 * @date     2021-09-11
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (isBadVersion(mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};
