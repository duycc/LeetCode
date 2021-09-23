/**
 * @file     lc_0977.cpp
 * @brief    https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int len = nums.size();
    vector<int> result(len);
    int k = len - 1;

    for (int i = 0, j = len - 1; i <= j;) {
      if (nums[i] * nums[i] < nums[j] * nums[j]) {
        result[k--] = nums[j] * nums[j];
        j--;
      } else {
        result[k--] = nums[i] * nums[i];
        i++;
      }
    }
    return result;
  }
};
