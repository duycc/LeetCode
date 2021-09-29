/**
 * @file     lc_0045.cpp
 * @brief    https://leetcode-cn.com/problems/jump-game-ii/
 * @author   YongDu
 * @date     2021-09-29
 */
class Solution {
public:
  int jump(vector<int> &nums) {
    int steps = 0;
    int currCover = 0;
    int nextCover = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      nextCover = std::max(nextCover, nums[i] + i);
      if (i == currCover) {
        steps++;
        currCover = nextCover;
      }
    }
    return steps;
  }
};
