/**
 * @file     lc_0215.cpp
 * @brief    https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> priQue; // 小顶堆

        for (int n : nums) {
            priQue.emplace(n);
            if (priQue.size() > k) {
                priQue.pop();
            }
        }

        return priQue.top();
    }
};
