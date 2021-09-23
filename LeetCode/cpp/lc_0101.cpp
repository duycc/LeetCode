/**
 * @file     lc_0101.cpp
 * @brief    https://leetcode-cn.com/problems/symmetric-tree/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (nullptr == root)
      return true;
    return compare(root->left, root->right);
  }

  bool compare(TreeNode *left, TreeNode *right) {
    if (!left && !right)
      return true;
    if (!left || !right)
      return false;
    if (left->val != right->val)
      return false;
    return compare(left->left, right->right) && compare(left->right, right->left);
  }
};
