/**
 * @file     lc_0452.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * @author   YongDu
 * @date     2021-10-17
 */
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    // 贪心
    std::sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2) { return p1[0] < p2[0]; });
    int minArrows = 1;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > points[i - 1][1]) {
        minArrows++;
      } else {
        points[i][1] = std::min(points[i - 1][1], points[i][1]);
      }
    }
    return minArrows;
  }
};
