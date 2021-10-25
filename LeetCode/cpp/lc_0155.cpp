/**
 * @file     lc_0155.cpp
 * @brief    https://leetcode-cn.com/problems/min-stack/
 * @author   DuYong
 * @date     2021-03-06
 */

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int val) {
    if (min_stack.empty() || val <= min_stack.top()) {
      min_stack.push(val);
    }
    val_stack.push(val);
  }

  void pop() {
    if (val_stack.empty()) {
      return;
    }
    if (val_stack.top() == min_stack.top()) {
      min_stack.pop();
    }
    val_stack.pop();
  }

  int top() { return val_stack.top(); }

  int getMin() { return min_stack.top(); }

private:
  std::stack<int> val_stack;
  std::stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
