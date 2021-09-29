/**
 * @file     lc_0238.cpp
 * @brief    https://leetcode-cn.com/problems/product-of-array-except-self/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    if (nums.empty()) {
      return vector<int>();
    }
    vector<int> result(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      result[i] = nums[i - 1] * result[i - 1];
    }
    int right = 1;
    for (int j = nums.size() - 1; j >= 0; --j) {
      result[j] *= right;
      right *= nums[j];
    }
    return result;
  }
};
