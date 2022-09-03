/**
 * @file     lc_0904.cpp
 * @brief    https://leetcode-cn.com/problems/fruit-into-baskets/
 * @author   YongDu
 * @date     2021-09-07
 */
class Solution {
  public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        int left = 0;

        std::unordered_map<int, int> hashMap; // <fruit, fruitCount>

        for (int right = 0; right < fruits.size(); ++right) {
            ++hashMap[fruits[right]];
            while (hashMap.size() > 2) {
                int curFruit = fruits[left];
                --hashMap[curFruit];
                if (hashMap[curFruit] == 0) {
                    hashMap.erase(curFruit);
                }
                ++left;
            }
            maxFruits = std::max(maxFruits, right - left + 1);
        }
        return maxFruits;
    }
};
