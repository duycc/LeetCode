/**
 * @file     lc_0135.cpp
 * @brief    https://leetcode-cn.com/problems/candy/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [Greedy Method] ----------------------------===//
// 1. 从左至右满足左边
// 2. 从右往左满足右边
//===----------------------------------------------------------------------===//
class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> candys(ratings.size(), 1);
    // -->
    for (int i = 1; i < candys.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candys[i] = candys[i - 1] + 1;
      }
    }
    // <--
    for (int i = candys.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        candys[i] = std::max(candys[i + 1] + 1, candys[i]);
      }
    }
    return std::accumulate(candys.begin(), candys.end(), 0);
  }
};
