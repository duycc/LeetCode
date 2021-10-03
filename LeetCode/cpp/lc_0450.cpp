/**
 * @file     lc_0450.cpp
 * @brief    https://leetcode-cn.com/problems/delete-node-in-a-bst/
 * @author   YongDu
 * @date     2021-10-03
 */
class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) {
      return root;
    }
    if (root->val == key) {
      if (root->left == nullptr) {
        return root->right;
      } else if (root->right == nullptr) {
        return root->left;
      } else {
        TreeNode *cur = root->right;
        while (cur->left) {
          cur = cur->left;
        }
        cur->left = root->left;
        TreeNode *tmp = root;
        root = root->right;
        delete tmp;
        return root;
      }
    }
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    }
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }
};
