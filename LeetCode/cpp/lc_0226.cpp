/**
 * @file     lc_0226.cpp
 * @brief    https://leetcode-cn.com/problems/invert-binary-tree/
 * @author   YongDu
 * @date     2021-09-10
 */
// 前序递归遍历
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};

// 迭代版
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    std::stack<TreeNode *> stk;
    TreeNode *node = root;
    stk.push(node);
    while (!stk.empty()) {
      node = stk.top();
      stk.pop();
      std::swap(node->left, node->right);
      if (node->right) {
        stk.push(node->right);
      }
      if (node->left) {
        stk.push(node->left);
      }
    }
    return root;
  }
};
