/**
 * @file     canJump.cpp
 * @brief    https://leetcode-cn.com/problems/jump-game/
 * @author   YongDu
 * @date     2021-08-15
 */
class Solution {
public:
  bool canJump(vector<int> &nums) {
    if (nums.empty()) {
      return false;
    }
    int len = nums.size();
#if 0 // 动态规划，超时
        vector<int> result(len, 0);
        result[0] = 1;
        for(int i = 1; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(result[j] && j + nums[j] >= i) {
                    result[i] = 1;
                    break;
                }
            }
        }
        return result[len-1];
#endif

    // 贪心
    if (1 == len)
      return true;
    int cover = 0;
    for (int i = 0; i <= cover; ++i) {
      cover = std::max(cover, i + nums[i]);
      if (cover >= len - 1) {
        return true;
      }
    }
    return false;
  }
};
