/**
 * @file     lc_0236.cpp
 * @brief    https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (nullptr == root || p == root || q == root)
      return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (!left)
      return right;
    if (!right)
      return left;

    return root;
  }
};
