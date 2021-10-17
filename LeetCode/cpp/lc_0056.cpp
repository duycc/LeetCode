/**
 * @file     lc_0056.cpp
 * @brief    https://leetcode-cn.com/problems/merge-intervals/
 * @author   YongDu
 * @date     2021-10-17
 */
class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> result;
    if (intervals.empty()) {
      return result;
    }
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int> &x, const vector<int> &y) { return x[0] < y[0]; });
    result.emplace_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= result.back()[1]) {
        result.back()[1] = std::max(intervals[i][1], result.back()[1]);
      } else {
        result.emplace_back(intervals[i]);
      }
    }
    return result;
  }
};
