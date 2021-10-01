/**
 * @file     lc_0572.cpp
 * @brief    https://leetcode-cn.com/problems/subtree-of-another-tree/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (subRoot == nullptr) {
      return true;
    }
    if (root == nullptr) {
      return false;
    }
    if (isSameTree(root, subRoot)) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

private:
  bool isSameTree(const TreeNode *left, const TreeNode *right) {
    if (!left && !right) {
      return true;
    }
    if (!left || !right) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    return isSameTree(left->left, right->left) && isSameTree(left->right, right->right);
  }
};
