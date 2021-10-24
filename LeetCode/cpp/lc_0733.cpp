/**
 * @file     lc_0733.cpp
 * @brief    https://leetcode-cn.com/problems/flood-fill/
 * @author   YongDu
 * @date     2021-10-24
 */
class Solution {
  const int dx[4] = {1, 0, 0, -1};
  const int dy[4] = {0, 1, -1, 0};

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int curColor = image[sr][sc];
    if (curColor == newColor) {
      return image;
    }
    int m = image.size(), n = image[0].size();
    std::queue<std::pair<int, int>> que;
    que.emplace(sr, sc);
    image[sr][sc] = newColor;
    while (!que.empty()) {
      int x = que.front().first, y = que.front().second;
      que.pop();
      for (int i = 0; i < 4; ++i) {
        int mx = x + dx[i], my = y + dy[i];
        if (mx >= 0 && mx < m && my >= 0 && my < n && image[mx][my] == curColor) {
          que.emplace(mx, my);
          image[mx][my] = newColor;
        }
      }
    }
    return image;
  }
};
