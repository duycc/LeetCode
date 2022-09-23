/**
 * @file     lc_0973.cpp
 * @brief    https://leetcode-cn.com/problems/k-closest-points-to-origin/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comp> pque; // 大顶堆

        for (auto& point : points) {
            pque.emplace(point);
            if (pque.size() > k) {
                pque.pop();
            }
        }

        while (!pque.empty()) {
            result.emplace_back(pque.top());
            pque.pop();
        }
        return result;
    }

  private:
    vector<vector<int>> result;

    struct Comp {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs) {
            return (pow(lhs[0], 2) + pow(lhs[1], 2)) < (pow(rhs[0], 2) + pow(rhs[1], 2));
        }
    };
};
