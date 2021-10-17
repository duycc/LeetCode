/**
 * @file     lc_0406.cpp
 * @brief    https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [Greedy Method] ----------------------------===//
// 1. 先按身高排序，身高相同按位置排序
// 2. 调整队列
//===----------------------------------------------------------------------===//
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    std::sort(people.begin(), people.end(), [](vector<int> &lhs, vector<int> &rhs) {
      return lhs[0] > rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
    });
    std::list<vector<int>> que;
    for (int i = 0; i < people.size(); ++i) {
      int pos = people[i][1];
      auto &&iter = que.begin();
      while (pos--) {
        iter++;
      }
      que.insert(iter, people[i]);
    }
    return vector<vector<int>>(que.begin(), que.end());
  }
};
