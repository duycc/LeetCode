/**
 * @file     jz_012.cpp
 * @brief    https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 * @author   YongDu
 * @date     2021-10-16
 */
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    rows = board.size();
    cols = board[0].size();
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (backtracking(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  int rows{0};
  int cols{0};

  bool backtracking(vector<vector<char>> &board, string &word, int i, int j, int k) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k]) {
      return false;
    }
    if (k == word.size() - 1) {
      return true;
    }
    board[i][j] = '\0';
    bool res = backtracking(board, word, i - 1, j, k + 1) || backtracking(board, word, i + 1, j, k + 1) ||
               backtracking(board, word, i, j - 1, k + 1) || backtracking(board, word, i, j + 1, k + 1);
    board[i][j] = word[k];
    return res;
  }
};
