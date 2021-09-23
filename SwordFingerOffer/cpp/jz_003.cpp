/**
 * @file     jz_003.cpp
 * @brief    https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    int result;
    vector<bool> exist(nums.size(), false);

    for (auto &num : nums) {
      if (exist[num]) {
        result = num;
        break;
      } else {
        exist[num] = true;
      }
    }

    return result;
  }
};
