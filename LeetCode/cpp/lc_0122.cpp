/**
 * @file     lc_0122.cpp
 * @brief    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [Greedy Method] ----------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    for (int i = 1; i < prices.size(); ++i) {
      maxPro += std::max(prices[i] - prices[i - 1], 0);
    }
    return maxPro;
  }
};
