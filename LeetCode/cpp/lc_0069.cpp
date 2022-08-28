/**
 * @file     lc_0069.cpp
 * @brief    https://leetcode-cn.com/problems/sqrtx/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
  public:
    int mySqrt(int x) {
        if (0 == x) {
            return 0;
        }
        int left = 1, right = x;
        int sqrt;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            sqrt = x / mid;
            if (sqrt == mid) {
                return sqrt;
            } else if (sqrt < mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};
