/**
 * @file     lc_0236.cpp
 * @brief    https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q) {
      return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == nullptr) {
      return right;
    }
    if (right == nullptr) {
      return left;
    }
    return root;
  }
};
