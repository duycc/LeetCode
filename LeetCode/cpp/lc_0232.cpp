/**
 * @file     lc_0232.cpp
 * @brief    https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * @author   YongDu
 * @date     2021-09-10
 */

class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { stk_in_.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (stk_out_.empty()) {
      while (!stk_in_.empty()) {
        stk_out_.push(stk_in_.top());
        stk_in_.pop();
      }
    }
    int result = stk_out_.top();
    stk_out_.pop();
    return result;
  }

  /** Get the front element. */
  int peek() {
    int res = this->pop();
    stk_out_.push(res);
    return res;
  }

  /** Returns whether the queue is empty. */
  bool empty() { return stk_in_.empty() && stk_out_.empty(); }

private:
  std::stack<int> stk_in_;
  std::stack<int> stk_out_;
};
