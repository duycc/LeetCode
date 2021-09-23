/**
 * @file     lc_0739.cpp
 * @brief    https://leetcode-cn.com/problems/daily-temperatures/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    // 单调栈寻找某元素左右最大元素
    if (temperatures.empty()) {
      return vector<int>();
    }
    std::stack<int> stk;
    vector<int> result(temperatures.size(), 0);
    stk.push(0);
    for (int i = 1; i < temperatures.size(); ++i) {
      while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
        result[stk.top()] = i - stk.top();
        stk.pop();
      }
      stk.push(i);
    }
    return result;
  }
};
