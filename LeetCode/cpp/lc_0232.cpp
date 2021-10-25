/**
 * @file     lc_0232.cpp
 * @brief    https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * @author   YongDu
 * @date     2021-09-10
 */
class MyQueue {
public:
  MyQueue() {}

  void push(int x) { inStk.push(x); }

  int pop() {
    if (this->empty()) {
      return -1;
    }
    if (outStk.empty()) {
      while (!inStk.empty()) {
        outStk.push(inStk.top());
        inStk.pop();
      }
    }
    int res = outStk.top();
    outStk.pop();
    return res;
  }

  int peek() {
    int res = this->pop();
    outStk.push(res);
    return res;
  }

  bool empty() { return inStk.empty() && outStk.empty(); }

private:
  std::stack<int> inStk;
  std::stack<int> outStk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
