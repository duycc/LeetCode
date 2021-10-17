/**
 * @file     lc_5904.cpp
 * @brief    https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets/
 * @author   YongDu
 * @date     2021-10-17
 */
class Solution {
public:
  int countMaxOrSubsets(vector<int> &nums) {
    int maxSum = 0;
    for (int n : nums) {
      maxSum |= n;
    }
    backtracking(nums, 0, maxSum, 0);
    return count;
  }

private:
  int count{0};

  void backtracking(vector<int> &nums, int idx, int maxSum, int curSum) {
    if (curSum == maxSum) {
      count++;
    }
    for (int i = idx; i < nums.size(); ++i) {
      backtracking(nums, i + 1, maxSum, curSum | nums[i]);
    }
  }
};
