/**
 * @file     lc_0001.cpp
 * @brief    https://leetcode-cn.com/problems/two-sum/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> indexMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (indexMap.find(target - nums[i]) != indexMap.end()) {
                return std::vector{i, indexMap[target - nums[i]]};
            } else {
                indexMap[nums[i]] = i;
            }
        }
        return std::vector<int>();
    }
};
