/**
 * @file     lc_0714.cpp
 * @brief    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 * @author   YongDu
 * @date     2021-10-18
 */
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int maxPro = 0;
    int minPrice = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < minPrice) {
        minPrice = prices[i];
      }
      if (prices[i] > minPrice + fee) {
        maxPro += prices[i] - minPrice - fee;
        minPrice = prices[i] - fee; // 防止重复减去手续费
      }
    }
    return maxPro;
  }
};
