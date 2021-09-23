/**
 * @file     ig_0406.cpp
 * @brief    https://leetcode-cn.com/problems/successor-lcci/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *node) {
    if (nullptr == node || nullptr == root)
      return nullptr;

    TreeNode *successor = node->right; // 后继节点

    if (successor) { // 存在右子树，后继节点为右子树最左节点
      while (successor->left) {
        successor = successor->left;
      }
      return successor;
    }

    // 不存在右子树，在root中找比它大的节点
    while (root) {
      if (node->val < root->val) {
        successor = root;
        root = root->left;
      } else {
        root = root->right;
      }
    }

    return successor;
  }
};
