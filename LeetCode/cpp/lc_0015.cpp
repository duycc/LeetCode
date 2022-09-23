/**
 * @file     lc_0015.cpp
 * @brief    https://leetcode-cn.com/problems/3sum/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                if (currSum < 0) {
                    left++;
                } else if (currSum > 0) {
                    right--;
                } else {
                    result.emplace_back(std::vector<int>{nums[i], nums[left], nums[right]});
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
        return result;
    }
};
