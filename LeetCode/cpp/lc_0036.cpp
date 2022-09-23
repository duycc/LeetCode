/**
 * @file     lc_0036.cpp
 * @brief    https://leetcode-cn.com/problems/valid-sudoku/
 * @author   YongDu
 * @date     2021-10-14
 */
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::vector<int>> rows(9, std::vector<int>(9, 0));
        std::vector<std::vector<int>> cols(9, std::vector<int>(9, 0));

        std::vector<std::vector<std::vector<int>>> subboxs(3, std::vector<std::vector<int>>(3, std::vector<int>(9, 0)));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int val = board[i][j] - '0' - 1;
                rows[i][val]++;
                cols[j][val]++;
                subboxs[i / 3][j / 3][val]++;
                if (rows[i][val] > 1 || cols[j][val] > 1 || subboxs[i / 3][j / 3][val] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};