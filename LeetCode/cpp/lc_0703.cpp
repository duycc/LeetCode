/**
 * @file     lc_0703.cpp
 * @brief    https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
 * @author   YongDu
 * @date     2021-09-11
 */

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> que; // 小顶堆
  int k;

public:
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    for (int elem : nums) {
      que.push(elem);
      if (que.size() > k)
        que.pop();
    }
  }

  int add(int val) {
    que.push(val);
    if (que.size() > k)
      que.pop();

    return que.top();
  }
};
