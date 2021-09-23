/**
 * @file     lc_0496.cpp
 * @brief    https://leetcode-cn.com/problems/next-greater-element-i/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty()) {
      return vector<int>();
    }
    // 使用 hashMap 映射 nums1 的索引，方便查找和更新 result
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums1.size(); ++i) {
      hashMap[nums1[i]] = i;
    }

    // 单调栈
    std::stack<int> stk;
    vector<int> result(nums1.size(), -1);
    stk.push(0);
    for (int i = 1; i < nums2.size(); ++i) {
      while (!stk.empty() && nums2[i] > nums2[stk.top()]) {
        if (hashMap.find(nums2[stk.top()]) != hashMap.end()) {
          result[hashMap[nums2[stk.top()]]] = nums2[i];
        }
        stk.pop();
      }
      stk.push(i);
    }
    return result;
  }
};
