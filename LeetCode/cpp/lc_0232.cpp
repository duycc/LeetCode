/**
 * @file     lc_0232.cpp
 * @brief    https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * @author   YongDu
 * @date     2021-09-10
 */

class MyQueue {
  public:
    MyQueue() {}

    void push(int x) { inStk_.push(x); }

    int pop() {
        if (empty()) {
            return -1;
        }
        if (outStk_.empty()) {
            while (!inStk_.empty()) {
                outStk_.push(inStk_.top());
                inStk_.pop();
            }
        }
        int result = outStk_.top();
        outStk_.pop();
        return result;
    }

    int peek() {
        int result = this->pop();
        outStk_.push(result);
        return result;
    }

    bool empty() { return inStk_.empty() && outStk_.empty(); }

  private:
    std::stack<int> inStk_;
    std::stack<int> outStk_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
