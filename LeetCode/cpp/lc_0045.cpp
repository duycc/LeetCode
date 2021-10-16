/**
 * @file     lc_0045.cpp
 * @brief    https://leetcode-cn.com/problems/jump-game-ii/
 * @author   YongDu
 * @date     2021-09-29
 */

//===------------------------- [普通贪心] ----------------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.size() == 1) {
      return 0;
    }
    int steps = 0;
    int curCover = 0;
    int nextCover = 0;
    for (int i = 0; i < nums.size(); ++i) {
      nextCover = std::max(i + nums[i], nextCover);
      if (i == curCover) {
        if (curCover == nums.size() - 1) {
          break;
        } else {
          steps++;
          curCover = nextCover;
          if (curCover >= nums.size() - 1) {
            break;
          }
        }
      }
    }
    return steps;
  }
};

//===------------------------- [贪心优化版] --------------------------------===//
//
//===----------------------------------------------------------------------===//
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
