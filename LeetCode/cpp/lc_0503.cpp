/**
 * @file     lc_0503.cpp
 * @brief    https://leetcode-cn.com/problems/next-greater-element-ii/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    if (nums.empty()) {
      return vector<int>();
    }
    vector<int> result(nums.size(), -1);
    std::stack<int> stk;
    for (int i = 0; i < 2 * nums.size(); ++i) {
      int index = i % nums.size();
      while (!stk.empty() && nums[index] > nums[stk.top()]) {
        result[stk.top()] = nums[index];
        stk.pop();
      }
      stk.push(index);
    }
    return result;
  }
};
