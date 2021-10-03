/**
 * @file     lc_0701.cpp
 * @brief    https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
 * @author   YongDu
 * @date     2021-10-03
 */
class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      TreeNode *node = new TreeNode(val);
      return node;
    }
    if (root->val > val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};

//===----------------------------- 迭代版 ------------------------------===//
class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return new TreeNode(val);
    }
    TreeNode *preNode = nullptr;
    TreeNode *curNode = root;
    while (curNode) {
      preNode = curNode;
      if (curNode->val > val) {
        curNode = curNode->left;
      } else if (curNode->val < val) {
        curNode = curNode->right;
      }
    }

    if (preNode->val < val) {
      preNode->right = new TreeNode(val);
    } else {
      preNode->left = new TreeNode(val);
    }
    return root;
  }
};
