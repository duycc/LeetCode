/**
 * @file     lc_0376.cpp
 * @brief    https://leetcode-cn.com/problems/wiggle-subsequence/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [Greedy Method] ----------------------------===//
// 丢弃单调过程中的冗余点，尽可能保留峰值
//===----------------------------------------------------------------------===//
class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    // 贪心
    int maxLen = 1;
    int preDiff = 0;
    int curDiff = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      curDiff = nums[i + 1] - nums[i];
      if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
        maxLen++;
        preDiff = curDiff; // 不可以放到if语句后，否则有可能丢失单调性
      }
    }
    return maxLen;
  }
};
