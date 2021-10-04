/**
 * @file     lc_0037.cpp
 * @brief    https://leetcode-cn.com/problems/sudoku-solver/
 * @author   YongDu
 * @date     2021-10-05
 */
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { (void)backtracking(board); }

private:
  bool backtracking(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] != '.') {
          continue;
        }
        for (char k = '1'; k <= '9'; ++k) {
          if (isValid(board, i, j, k)) {
            board[i][j] = k;
            if (backtracking(board)) {
              return true;
            }
            board[i][j] = '.';
          }
        }
        return false; // 9个数都不行，即不存在可行的方案
      }
    }
    return true;
  }

  bool isValid(vector<vector<char>> &board, int row, int col, char val) {
    // 同一行
    for (int i = 0; i < board[0].size(); ++i) {
      if (board[row][i] == val) {
        return false;
      }
    }

    // 同一列
    for (int i = 0; i < board.size(); ++i) {
      if (board[i][col] == val) {
        return false;
      }
    }

    // 3 * 3宫格
    int rowBegin = row / 3 * 3;
    int colBegin = col / 3 * 3;
    for (int i = rowBegin; i < rowBegin + 3; ++i) {
      for (int j = colBegin; j < colBegin + 3; ++j) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }
    return true;
  }
};
