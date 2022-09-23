/**
 * @file     lc_0560.cpp
 * @brief    https://leetcode-cn.com/problems/subarray-sum-equals-k/
 * @author   YongDu
 * @date     2021-09-11
 */
// 前缀和 + 哈希查找
class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> preSumMap;
        preSumMap[0] = 1;
        int result = 0;
        int curSum = 0;
        for (int n : nums) {
            curSum += n;
            if (preSumMap.find(curSum - k) != preSumMap.end()) {
                result += preSumMap[curSum - k];
            }
            preSumMap[curSum]++;
        }
        return result;
    }
};
