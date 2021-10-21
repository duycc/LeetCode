/**
 * @file     lc_0746.cpp
 * @brief    https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * @author   YongDu
 * @date     2021-10-21
 */
class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int dp0 = cost[0];
    int dp1 = cost[1];
    for (int i = 2; i < cost.size(); ++i) {
      int dpi = std::min(dp0, dp1) + cost[i];
      dp0 = dp1;
      dp1 = dpi;
    }
    return std::min(dp0, dp1);
  }
};
