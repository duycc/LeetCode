/**
 * @file     lc_0239.cpp
 * @brief    https://leetcode-cn.com/problems/sliding-window-maximum/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  // 单调队列实现
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    MyQueue que;
    vector<int> result;
    for (int i = 0; i < k; ++i) {
      que.push(nums[i]);
    }
    result.push_back(que.front());
    for (int i = k; i < nums.size(); ++i) {
      que.pop(nums[i - k]);
      que.push(nums[i]);
      result.push_back(que.front());
    }
    return result;
  }

private:
  struct MyQueue {
    std::deque<int> que_;

    void pop(int value) {
      if (!que_.empty() && value == que_.front()) {
        que_.pop_front();
      }
      return;
    }

    void push(int value) {
      while (!que_.empty() && que_.back() < value) {
        que_.pop_back();
      }
      que_.emplace_back(value);
      return;
    }

    int front() const { return que_.front(); }
  };
};
