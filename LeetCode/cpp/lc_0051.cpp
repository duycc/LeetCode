/**
 * @file     lc_0051.cpp
 * @brief    https://leetcode-cn.com/problems/n-queens/
 * @author   YongDu
 * @date     2021-09-27
 */
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    if (n <= 0) {
      return result;
    }
    backTrack(n, 0, chessbord);
    return result;
  }

private:
  vector<vector<string>> result;
  vector<string> chessbord(n, string(n, '.'));

  void backTrack(int n, int row, vector<string> &chessbord) {
    if (row == n) {
      result.emplace_back(chessbord);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (isValid(row, col, chessbord)) {
        chessbord[row][col] = 'Q';
        backTrack(n, row + 1, chessbord);
        chessbord[row][col] = '.';
      }
    }
    return;
  }

  bool isValid(int row, int col, vector<string> &chessbord) {
    // 检查列
    for (int i = 0; i < row; ++i) {
      if (chessbord[i][col] == 'Q') {
        return false;
      }
    }

    // 检查左上角
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (chessbord[i][j] == 'Q') {
        return false;
      }
    }

    // 检查右上角
    for (int i = row - 1, j = col + 1; i >= 0 && j < chessbord.size(); --i, ++j) {
      if (chessbord[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
};
