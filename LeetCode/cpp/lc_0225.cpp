/**
 * @file     lc_0225.cpp
 * @brief    https://leetcode-cn.com/problems/implement-stack-using-queues/
 * @author   YongDu
 * @date     2021-09-11
 */

//===------------------------- [Two Queue] --------------------------------===//
// 两个队列实现
//===----------------------------------------------------------------------===//
class MyStack {
public:
  MyStack() {}

  void push(int x) { dataQue.push(x); }

  int pop() {
    int size = dataQue.size();
    size--;
    while (size--) {
      helpQue.push(dataQue.front());
      dataQue.pop();
    }
    int res = dataQue.front();
    dataQue.pop();
    dataQue = helpQue;
    while (!helpQue.empty()) {
      helpQue.pop();
    }
    return res;
  }

  int top() { return dataQue.back(); }

  bool empty() { return dataQue.empty(); }

private:
  std::queue<int> dataQue;
  std::queue<int> helpQue;
};

//===------------------------- [One Queue] --------------------------------===//
// 一个队列实现
//===----------------------------------------------------------------------===//
class MyStack {
public:
  MyStack() {}

  void push(int x) { dataQue.push(x); }

  int pop() {
    int size = dataQue.size();
    while (--size) {
      dataQue.push(dataQue.front());
      dataQue.pop();
    }
    int res = dataQue.front();
    dataQue.pop();
    return res;
  }

  int top() { return dataQue.back(); }

  bool empty() { return dataQue.empty(); }

private:
  std::queue<int> dataQue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
