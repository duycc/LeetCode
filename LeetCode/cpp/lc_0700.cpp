/**
 * @file     lc_0700.cpp
 * @brief    https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
 * @author   YongDu
 * @date     2021-10-03
 */
class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr || root->val == val) {
      return root;
    } else if (root->val < val) {
      return searchBST(root->right, val);
    } else {
      return searchBST(root->left, val);
    }
    return nullptr;
  }
};

//===----------------------------- 迭代版 ------------------------------===//
class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root != nullptr) {
      if (root->val > val) {
        root = root->left;
      } else if (root->val < val) {
        root = root->right;
      } else {
        return root;
      }
    }
    return nullptr;
  }
};
