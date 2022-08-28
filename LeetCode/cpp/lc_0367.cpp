/**
 * @file     lc_0367.cpp
 * @brief    https://leetcode-cn.com/problems/valid-perfect-square/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    bool isPerfectSquare(int num) {
        if (num <= 0) {
            return false;
        }
        int left  = 1;
        int right = num;
        int mid, sqrt;
        while (left <= right) {
            mid  = left + ((right - left) >> 1);
            sqrt = num / mid;
            if (sqrt == mid && num % sqrt == 0) { // 保证是整除
                return true;
            } else if (sqrt < mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
