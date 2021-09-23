/**
 * @file     canCompleteCircuit.cpp
 * @brief    https://leetcode-cn.com/problems/gas-station/
 * @author   YongDu
 * @date     2021-08-30
 */
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < cost.size(); ++i) {
      curSum += gas[i] - cost[i];
      totalSum += gas[i] - cost[i];
      if (curSum < 0) {
        start = i + 1;
        curSum = 0;
      }
    }

    if (totalSum < 0) {
      return -1;
    }
    return start;
  }
};
