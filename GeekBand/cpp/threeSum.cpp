/**
 * @file     threeSum.cpp
 * @brief    https://leetcode-cn.com/problems/3sum/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) { // 去重
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        if (nums[i] + nums[left] + nums[right] > 0) {
          right--;
        } else if (nums[i] + nums[left] + nums[right] < 0) {
          left++;
        } else {
          result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
          while (left < right && nums[right] == nums[right - 1]) {
            right--;
          }
          while (left < right && nums[left] == nums[left + 1]) {
            left++;
          }
          right--;
          left++;
        }
      }
    }
    return result;
  }
};
