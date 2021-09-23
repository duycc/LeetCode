/**
 * @file     productExceptSelf.cpp
 * @brief    https://leetcode-cn.com/problems/product-of-array-except-self/
 * @author   YongDu
 * @date     2021-08-30
 */
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int len = nums.size();
    vector<int> result(len, 1);
    for (int i = 1; i < len; ++i) {
      result[i] = nums[i - 1] * result[i - 1];
    }
    int right = 1;
    for (int i = len - 1; i >= 0; --i) {
      result[i] *= right;
      right *= nums[i];
    }
    return result;
  }
};
