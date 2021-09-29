/**
 * @file     lc_0095.cpp
 * @brief    https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 * @author   YongDu
 * @date     2021-09-29
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0) {
      return {nullptr};
    }
    return generateTrees(1, n);
  }

private:
  vector<TreeNode *> generateTrees(int begin, int end) {
    if (begin > end) {
      return {nullptr};
    }
    vector<TreeNode *> allTrees;
    for (int i = begin; i <= end; ++i) {
      vector<TreeNode *> leftTrees = generateTrees(begin, i - 1);
      vector<TreeNode *> rightTrees = generateTrees(i + 1, end);

      for (auto &left : leftTrees) {
        for (auto &right : rightTrees) {
          TreeNode *currTree = new TreeNode(i);
          currTree->left = left;
          currTree->right = right;
          allTrees.emplace_back(currTree);
        }
      }
    }
    return allTrees;
  }
};
