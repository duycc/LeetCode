/**
 * @file     lc_0016.cpp
 * @brief    https://leetcode-cn.com/problems/3sum-closest/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int nearestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                nearestSum = std::abs(currSum - target) < std::abs(nearestSum - target) ? currSum : nearestSum;
                if (currSum > target) {
                    right--;
                } else if (currSum < target) {
                    left++;
                } else {
                    return target;
                }
            }
        }
        return nearestSum;
    }
};
