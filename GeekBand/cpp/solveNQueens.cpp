/**
 * @file     solveNQueens.cpp
 * @brief    https://leetcode-cn.com/problems/n-queens/
 * @author   YongDu
 * @date     2021-09-02
 */
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<string> chessboard(n, string(n, '.'));
    backTrack(n, 0, chessboard);
    return result;
  }

private:
  vector<vector<string>> result;

  void backTrack(int n, int row, vector<string> &chessboard) {
    if (row == n) {
      result.emplace_back(chessboard);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (isValid(row, col, n, chessboard)) {
        chessboard[row][col] = 'Q';
        backTrack(n, row + 1, chessboard);
        chessboard[row][col] = '.';
      }
    }
    return;
  }

  bool isValid(int row, int col, int n, vector<string> &chessboard) {
    // 同列
    for (int i = 0; i < row; ++i) {
      if (chessboard[i][col] == 'Q') {
        return false;
      }
    }
    // 左上角
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    // 右上角
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (chessboard[i][j] == 'Q') {
        return false;
      }
    }
    return true;
  }
};
