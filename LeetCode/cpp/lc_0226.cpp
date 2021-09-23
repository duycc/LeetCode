/**
 * @file     lc_0226.cpp
 * @brief    https://leetcode-cn.com/problems/invert-binary-tree/
 * @author   YongDu
 * @date     2021-09-10
 */
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (nullptr == root)
      return nullptr;

    swap(root->left, root->right);
    if (root->left)
      invertTree(root->left);
    if (root->right)
      invertTree(root->right);

    return root;
  }
};
