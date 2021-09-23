/**
 * @file     lc_0225.cpp
 * @brief    https://leetcode-cn.com/problems/implement-stack-using-queues/
 * @author   YongDu
 * @date     2021-09-11
 */

/*----- 两个队列实现 -----*/
class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) { que_data_.push(x); }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int size = que_data_.size();
    size--; // 需要留下最后一个元素
    while (size--) {
      que_transfer_.push(que_data_.front());
      que_data_.pop();
    }
    int res = que_data_.front();
    que_data_.pop();
    que_data_ = que_transfer_;
    while (!que_transfer_.empty()) {
      que_transfer_.pop();
    }
    return res;
  }

  /** Get the top element. */
  int top() { return que_data_.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return que_data_.empty(); }

private:
  std::queue<int> que_data_;
  std::queue<int> que_transfer_;
};

/*----- 一个队列实现 -----*/
class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) { que_data_.push(x); }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int size = que_data_.size();
    while (--size) { // 注意是不能是 size--
      que_data_.push(que_data_.front());
      que_data_.pop();
    }
    int res = que_data_.front();
    que_data_.pop();
    return res;
  }

  /** Get the top element. */
  int top() { return que_data_.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return que_data_.empty(); }

private:
  std::queue<int> que_data_;
};
