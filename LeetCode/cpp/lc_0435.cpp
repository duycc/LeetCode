/**
 * @file     lc_0435.cpp
 * @brief    https://leetcode-cn.com/problems/non-overlapping-intervals/
 * @author   YongDu
 * @date     2021-10-17
 */
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    // 贪心
    if (intervals.empty()) {
      return 0;
    }
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &x, const vector<int> &y) { return x[1] < y[1]; });
    int end = intervals[0][1]; // 非重叠区间末尾
    int unlap = 1;             // 非重叠区间个数
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= end) {
        unlap++;
        end = intervals[i][1];
      }
    }
    return intervals.size() - unlap;
  }
};
