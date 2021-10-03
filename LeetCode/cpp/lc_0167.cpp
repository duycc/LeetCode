/**
 * @file     lc_0167.cpp
 * @brief    https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 * @author   YongDu
 * @date     2021-10-04
 */
//===----------------------------- 双指针法 ------------------------------===//
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int begin = 0;
    int end = numbers.size() - 1;
    while (begin < end) {
      int curSum = numbers[begin] + numbers[end];
      if (curSum > target) {
        end--;
      } else if (curSum < target) {
        begin++;
      } else {
        return vector<int>{begin + 1, end + 1};
      }
    }
    return vector<int>();
  }
};
