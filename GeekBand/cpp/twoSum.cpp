/**
 * @file     twoSum.cpp
 * @brief    https://leetcode-cn.com/problems/two-sum/
 * @author   YongDu
 * @date     2021-09-05
 */
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> valueToIndex;
    for (int i = 0; i < nums.size(); ++i) {
      if (valueToIndex.find(target - nums[i]) != valueToIndex.end()) {
        return vector<int>{i, valueToIndex[target - nums[i]]};
      } else {
        valueToIndex[nums[i]] = i;
      }
    }
    return vector<int>();
  }
};
