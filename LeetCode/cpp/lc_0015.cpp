/**
 * @file     lc_0015.cpp
 * @brief    https://leetcode-cn.com/problems/3sum/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
      return result;
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) { // 数组已排序，第一个 > 0，则和不可能为0
        return result;
      }
      if (i > 0 && nums[i] == nums[i - 1]) { // 去重
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        if ((nums[i] + nums[left] + nums[right]) > 0) {
          right--;
        } else if ((nums[i] + nums[left] + nums[right]) < 0) {
          left++;
        } else {
          result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) { // 去重
            left++;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            right--;
          }
          right--; // 收缩双指针
          left++;
        }
      }
    }
    return result;
  }
};
