/**
 * @file     lc_5886.cpp
 * @brief    https://leetcode-cn.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
 * @author   YongDu
 * @date     2021-10-17
 */

//===------------------------- [Greedy Method] ----------------------------===//
// 1. 统计字符串中连续相同的子字符串"AAA..."或者"BBB..."中可操作的个数
// 2. 且A和B相互独立，最后只要统计谁的次数多谁就可以获胜
//===----------------------------------------------------------------------===//
class Solution {
public:
  bool winnerOfGame(string colors) {
    int operA = 0;
    int operB = 0;
    for (int i = 1; i < colors.size() - 1; ++i) {
      if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') {
        operA++;
        continue;
      }
      if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') {
        operB++;
      }
    }
    return operA > operB;
  }
};
