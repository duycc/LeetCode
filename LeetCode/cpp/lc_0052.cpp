/**
 * @file     lc_0052.cpp
 * @brief    https://leetcode-cn.com/problems/n-queens-ii/
 * @author   YongDu
 * @date     2021-09-27
 */
class Solution {
public:
  int totalNQueens(int n) {
    vector<string> chessboard(n, string(n, '.'));
    backTrack(n, 0, chessboard);
    return count;
  }

private:
  int count{0};

  void backTrack(int n, int row, vector<string> &chessboard) {
    if (row == n) {
      count++;
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
