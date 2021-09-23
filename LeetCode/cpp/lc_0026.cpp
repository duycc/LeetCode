/**
 * @file     lc_0026.cpp
 * @brief    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int index = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[index]) {
        nums[++index] = nums[i];
      }
    }
    return index + 1;
  }
};
