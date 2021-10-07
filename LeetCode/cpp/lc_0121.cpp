/**
 * @file     lc_0121.cpp
 * @brief    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * @author   YongDu
 * @date     2021-10-07
 */
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int result = 0;
    int low = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
      low = std::min(prices[i], low);
      result = std::max(prices[i] - low, result);
    }
    return result;
  }
};
