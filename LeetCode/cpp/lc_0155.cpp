/**
 * @file     lc_0155.cpp
 * @brief    https://leetcode-cn.com/problems/min-stack/
 * @author   DuYong
 * @date     2021-03-06
 */
class MinStack {
  public:
    MinStack() {}

    void push(int val) {
        if (minStk_.empty() || val <= minStk_.top()) {
            minStk_.push(val);
        }
        valStk_.push(val);
    }

    void pop() {
        if (valStk_.empty()) {
            return;
        }
        if (minStk_.top() == valStk_.top()) {
            minStk_.pop();
        }
        valStk_.pop();
    }

    int top() { return valStk_.top(); }

    int getMin() { return minStk_.top(); }

  private:
    std::stack<int> valStk_;
    std::stack<int> minStk_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */