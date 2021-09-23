/**
 * @file     smallestK2.cpp
 * @brief    https://leetcode-cn.com/problems/smallest-k-lcci/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<int> smallestK(vector<int> &arr, int k) {
    std::priority_queue<int, vector<int>, greater<int>> priQue{arr.begin(), arr.end()};
    vector<int> result;
    for (int i = 0; i < k; ++i) {
      result.emplace_back(priQue.top());
      priQue.pop();
    }
    return result;
  }
};
