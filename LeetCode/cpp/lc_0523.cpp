/**
 * @file     lc_0523.cpp
 * @brief    https://leetcode-cn.com/problems/continuous-subarray-sum/
 * @author   YongDu
 * @date     2021-09-11
 */
class Solution {
  public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // 前缀和 + 同余定理
        std::unordered_map<int, int> remainMap;
        remainMap[0] = -1;
        int remainder = 0;
        for (int i = 0; i < nums.size(); ++i) {
            remainder = (remainder + nums[i]) % k;
            if (remainMap.find(remainder) != remainMap.end()) {
                if ((i - remainMap[remainder]) >= 2) {
                    return true;
                }
            } else {
                remainMap[remainder] = i;
            }
        }
        return false;
    }
};
