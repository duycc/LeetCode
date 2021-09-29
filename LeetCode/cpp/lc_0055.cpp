/**
 * @file     lc_0055.cpp
 * @brief    https://leetcode-cn.com/problems/jump-game/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  bool canJump(vector<int> &nums) {
    int cover = 0;
    if (nums.size() == 1) {
      return true;
    }
    for (int i = 0; i <= cover; ++i) {
      cover = std::max(i + nums[i], cover);
      if (cover >= nums.size() - 1) {
        return true;
      }
    }
    return false;
  }
};
