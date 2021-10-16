/**
 * @file     lc_5885.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-number-of-moves-to-seat-everyone/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [Greedy Method] ----------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  int minMovesToSeat(vector<int> &seats, vector<int> &students) {
    std::sort(seats.begin(), seats.end());
    std::sort(students.begin(), students.end());
    int minMoves = 0;
    for (int i = 0; i < seats.size(); ++i) {
      minMoves += std::abs(seats[i] - students[i]);
    }
    return minMoves;
  }
};
