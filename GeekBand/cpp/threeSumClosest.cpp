/**
 * @file     threeSumClosest.cpp
 * @brief    https://leetcode-cn.com/problems/3sum-closest/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    int closetSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size(); ++i) {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int curSum = nums[i] + nums[left] + nums[right];
        closetSum = std::abs(curSum - target) < std::abs(closetSum - target) ? curSum : closetSum;
        if (curSum > target) {
          --right;
        } else if (curSum < target) {
          ++left;
        } else {
          return target;
        }
      }
    }
    return closetSum;
  }
};
