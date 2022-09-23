/**
 * @file     lc_0202.cpp
 * @brief    https://leetcode-cn.com/problems/happy-number/
 * @author   YongDu
 * @date     2021-09-08
 */

class Solution {
  public:
    bool isHappy(int n) {
        std::unordered_set<int> sumSet;
        while (true) {
            int sum = getPosSum(n);
            if (sum == 1) {
                break;
            } else if (sumSet.find(sum) != sumSet.end()) {
                return false;
            } else {
                sumSet.emplace(sum);
                n = sum;
            }
        }
        return true;
    }

  private:
    int getPosSum(int num) {
        int sum = 0;
        while (num) {
            sum += std::pow(num % 10, 2);
            num /= 10;
        }
        return sum;
    }
};
