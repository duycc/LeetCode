/**
 * @file     lc_0455.cpp
 * @brief    https://leetcode-cn.com/problems/assign-cookies/
 * @author   YongDu
 * @date     2021-10-17
 */
//===------------------------- [Greedy Method] ----------------------------===//
// 大饼干先满足大胃口的孩子或者小饼干先满足小孩子都可以
//===----------------------------------------------------------------------===//
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    int maxChilds = 0;
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int i = g.size() - 1;
    int j = s.size() - 1;
    while (i >= 0 && j >= 0) {
      if (s[j] >= g[i]) {
        maxChilds++;
        j--;
      }
      i--;
    }
    return maxChilds;
  }
};
