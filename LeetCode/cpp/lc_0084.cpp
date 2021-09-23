/**
 * @file     lc_0084.cpp
 * @brief    https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    // 动态规划
    if (heights.empty()) {
      return 0;
    }
    int len = heights.size();
    vector<int> leftMinIdx(len);
    vector<int> rightMinIdx(len);

    // 记录每个柱子两端第一个小于该柱子的柱子下标
    leftMinIdx[0] = -1;
    for (int i = 1; i < len; ++i) {
      int k = i - 1;
      while (k >= 0 && heights[k] >= heights[i]) {
        k = leftMinIdx[k];
      }
      leftMinIdx[i] = k;
    }
    rightMinIdx[len - 1] = len;
    for (int i = len - 2; i >= 0; --i) {
      int k = i + 1;
      while (k < len && heights[k] >= heights[i]) {
        k = rightMinIdx[k];
      }
      rightMinIdx[i] = k;
    }

    // 求最大面积
    int area = 0;
    for (int i = 0; i < len; ++i) {
      area = std::max(area, (heights[i] * (rightMinIdx[i] - leftMinIdx[i] - 1)));
    }
    return area;
  }
};

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    // 单调栈 版本一
    std::stack<int> stk;
    heights.insert(heights.begin(), 0);
    heights.emplace_back(0);
    stk.push(0);
    int area = 0;

    for (int i = 1; i < heights.size(); ++i) {
      if (heights[i] > heights[stk.top()]) {
        stk.push(i);
      } else if (heights[i] == heights[stk.top()]) {
        stk.pop();
        stk.push(i);
      } else {
        while (heights[i] < heights[stk.top()]) {
          int mid = stk.top();
          stk.pop();
          int h = heights[mid];
          int w = i - stk.top() - 1;
          area = std::max(area, h * w);
        }
        stk.push(i);
      }
    }
    return area;
  }
};

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    // 单调栈 版本二
    std::stack<int> stk;
    heights.insert(heights.begin(), 0);
    heights.emplace_back(0);
    stk.push(0);
    int area = 0;

    for (int i = 1; i < heights.size(); ++i) {
      while (heights[i] < heights[stk.top()]) {
        int mid = stk.top();
        stk.pop();
        int h = heights[mid];
        int w = i - stk.top() - 1;
        area = std::max(area, h * w);
      }
      stk.push(i);
    }
    return area;
  }
};
