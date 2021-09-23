/**
 * @file     trap.cpp
 * @brief    https://leetcode-cn.com/problems/trapping-rain-water/
 * @author   YongDu
 * @date     2021-08-30
 */

/* 动态规划 */
class Solution {
public:
  int trap(vector<int> &height) {
    int len = height.size();
    vector<int> leftMax(len, 0);
    vector<int> rightMax(len, 0);

    // 每个柱子左边的最大高度
    leftMax[0] = height[0];
    for (int i = 1; i < len; ++i) {
      leftMax[i] = std::max(height[i], leftMax[i - 1]);
    }
    // 每个柱子右边的最大高度
    rightMax[len - 1] = height[len - 1];
    for (int i = len - 2; i >= 0; --i) {
      rightMax[i] = std::max(height[i], rightMax[i + 1]);
    }

    int sum = 0;
    for (int i = 0; i < len; ++i) {
      int quantity = std::min(leftMax[i], rightMax[i]) - height[i];
      sum += (quantity > 0) ? quantity : 0;
    }
    return sum;
  }
};

/* 单调栈 */
class Solution {
public:
  int trap(vector<int> &height) {
    std::stack<int> stk; // 柱子下标
    stk.push(0);
    int sum = 0;
    for (int i = 1; i < height.size(); ++i) {
      if (height[i] < height[stk.top()]) {
        stk.push(i);
      } else if (height[i] == height[stk.top()]) {
        stk.pop();
        stk.push(i);
      } else {
        while (!stk.empty() && height[i] > height[stk.top()]) {
          int mid = stk.top();
          stk.pop();
          if (!stk.empty()) {
            int h = std::min(height[i], height[stk.top()]) - height[mid];
            int w = i - stk.top() - 1; // 只求中间宽度
            sum += h * w;
          }
        }
        stk.push(i);
      }
    }
    return sum;
  }
};
