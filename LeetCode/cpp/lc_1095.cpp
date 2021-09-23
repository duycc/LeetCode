/**
 * @file     lc_1095.cpp
 * @brief    https://leetcode-cn.com/problems/find-in-mountain-array/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    // 寻找山峰峰值
    int left = 0, right = mountainArr.length() - 1;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    int peak = left; // 峰值
    // 求最小下标，先搜索左半边
    int index = binarySearch(mountainArr, target, 0, peak, std::less<int>());
    return index != -1 ? index
                       : binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, std::greater<int>());
  }

private:
  // 此处二分辅助函数需要参数 comp，因为山峰数组左边是递增序列，右边是递减序列，二分逻辑正好相反
  template <typename _Compare>
  int binarySearch(MountainArray &mountainArr, int target, int start, int end, _Compare comp) {
    while (start <= end) {
      int mid = start + ((end - start) >> 1);
      if (mountainArr.get(mid) == target) {
        return mid;
      } else if (comp(mountainArr.get(mid), target)) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return -1;
  }
};
