/**
 * @file     ig_1714.cpp
 * @brief    https://leetcode-cn.com/problems/smallest-k-lcci/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
public:
  vector<int> smallestK(vector<int> &arr, int k) {
    vector<int> result;
    priority_queue<int> que;

    for (int elem : arr) {
      que.push(elem);
      if (que.size() > k) {
        que.pop();
      }
    }

    while (!que.empty()) {
      result.emplace_back(que.top());
      que.pop();
    }

    return result;
  }
};
