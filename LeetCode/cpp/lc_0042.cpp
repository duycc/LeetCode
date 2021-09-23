/**
 * @file     lc_0042.cpp
 * @brief    https://leetcode-cn.com/problems/trapping-rain-water/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  int trap(vector<int> &height) {
    /*  动态规划
        每一列雨水 = 该列左右侧两侧最高柱子中的较小值 - 柱子本身高度
        左右两侧柱子不接水
    */
    if (height.size() <= 2) {
      return 0;
    }
    vector<int> leftMax(height.size(), 0);
    vector<int> rightMax(height.size(), 0);
    int len = height.size();

    // 记录每个柱子左右两侧最大高度
    leftMax[0] = height[0];
    for (int i = 1; i < len; ++i) {
      leftMax[i] = std::max(height[i], leftMax[i - 1]);
    }
    rightMax[len - 1] = height[len - 1];
    for (int i = len - 2; i >= 0; --i) {
      rightMax[i] = std::max(height[i], rightMax[i + 1]);
    }

    // 可接雨水求和
    int sum = 0;
    for (int i = 0; i < len; ++i) {
      int cur = std::min(leftMax[i], rightMax[i]) - height[i];
      sum += (cur > 0 ? cur : 0);
    }
    return sum;
  }
};

class Solution {
public:
  int trap(vector<int> &height) {
    /*  单调栈
        按行计算
    */
    if (height.size() <= 2) {
      return 0;
    }
    std::stack<int> stk; // 保存柱子下标
    stk.push(0);
    int sum = 0;

    for (int i = 1; i < height.size(); ++i) {
      while (!stk.empty() && height[i] > height[stk.top()]) {
        int mid = stk.top();
        stk.pop();
        if (!stk.empty()) {
          int h = std::min(height[i], height[stk.top()]) - height[mid];
          int w = i - stk.top() - 1;
          sum += h * w;
        }
      }
      stk.push(i);
    }
    return sum;
  }
};
