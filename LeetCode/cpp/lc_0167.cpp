/**
 * @file     lc_0167.cpp
 * @brief    https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * @author   YongDu
 * @date     2021-10-04
 */
class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 双指针法
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int curSum = numbers[left] + numbers[right];
            if (curSum < target) {
                left++;
            } else if (curSum > target) {
                right--;
            } else {
                return std::vector<int>{left + 1, right + 1};
            }
        }
        return std::vector<int>();
    }
};
