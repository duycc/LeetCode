/**
 * @file     lc_0215.cpp
 * @brief    https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<>> priQue; // 小顶堆

    for (auto &num : nums) {
      priQue.emplace(num);
      if (priQue.size() > k) {
        priQue.pop();
      }
    }

    return priQue.top();
  }
};
