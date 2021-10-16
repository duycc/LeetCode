/**
 * @file     jz_009.cpp
 * @brief    https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 * @author   YongDu
 * @date     2021-10-16
 */
class CQueue {
public:
  CQueue() {}

  void appendTail(int value) { stk_in.push(value); }

  int deleteHead() {
    int ret = -1;
    if (stk_in.empty() && stk_out.empty()) {
      return ret;
    }
    if (stk_out.empty()) {
      while (!stk_in.empty()) {
        stk_out.push(stk_in.top());
        stk_in.pop();
      }
    }
    ret = stk_out.top();
    stk_out.pop();
    return ret;
  }

private:
  std::stack<int> stk_in;
  std::stack<int> stk_out;
};
