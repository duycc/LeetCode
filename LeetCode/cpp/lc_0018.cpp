/**
 * @file     lc_0018.cpp
 * @brief    https://leetcode-cn.com/problems/4sum/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    if (nums.size() < 4U) {
      return result;
    }
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      // if(nums[i] > target) { // 不可剪枝
      //     return result;
      // }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) { // long long 防止整型溢出
          long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
          if (sum > target) {
            right--;
          } else if (sum < target) {
            left++;
          } else {
            result.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }
            left++;
            right--;
          }
        }
      }
    }
    return result;
  }
};
