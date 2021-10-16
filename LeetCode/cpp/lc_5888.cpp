/**
 * @file     lc_5888.cpp
 * @brief    https://leetcode-cn.com/problems/the-time-when-the-network-becomes-idle/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [BFS] --------------------------------------===//
// 数学推导 + 广度优先搜索
//===----------------------------------------------------------------------===//
class Solution {
public:
  int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
    int srvNum = patience.size();
    int maxTime = 0; // 最后一个包最晚到达时间

    // 建立邻接表
    vector<vector<int>> e(srvNum);
    for (auto &edge : edges) {
      e[edge[0]].push_back(edge[1]);
      e[edge[1]].push_back(edge[0]);
    }

    // 访问数组
    vector<bool> visit(srvNum, false);
    visit[0] = true;

    // BFS
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(0, 0));
    while (!que.empty()) {
      auto [srv, time] = que.front();
      que.pop();

      if (srv != 0) {
        int cost = ((2 * time - 1) / patience[srv]) * patience[srv] + 2 * time;
        maxTime = std::max(cost, maxTime);
      }

      for (int next : e[srv]) {
        if (!visit[next]) {
          visit[next] = true;
          que.push(std::make_pair(next, time + 1));
        }
      }
    }

    return maxTime + 1;
  }
};
