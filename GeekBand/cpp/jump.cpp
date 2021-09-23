/**
 * @file     jump.cpp
 * @brief    https://leetcode-cn.com/problems/jump-game-ii/
 * @author   YongDu
 * @date     2021-08-17
 */
class Solution {
public:
  int jump(vector<int> &nums) {
    int steps = 0;        // 最少跳跃次数
    int curDistance = 0;  // 当前覆盖最远距离下标
    int nextDistance = 0; // 下一步覆盖最远距离下标
    for (int i = 0; i < nums.size() - 1; ++i) {
      nextDistance = std::max(nextDistance, nums[i] + i);
      if (i == curDistance) {
        steps++;
        curDistance = nextDistance;
      }
    }
    return steps;
  }
};
