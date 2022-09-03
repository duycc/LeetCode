/**
 * @file     thirdMax.cpp
 * @brief
 * @author   DuYong
 * @date     2021-03-09
 */
class Solution {
  public:
    int thirdMax(vector<int>& nums) {
        std::set<int> numSet;
        for (int n : nums) {
            numSet.insert(n);
            if (numSet.size() > 3) {
                numSet.erase(numSet.begin());
            }
        }
        return numSet.size() == 3 ? *(numSet.begin()) : *(--numSet.end());
    }
};