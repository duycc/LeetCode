/**
 * @file     lc_0235.cpp
 * @brief    https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * @author   YongDu
 * @date     2021-09-10
 */
/**
 * @file     lowestCommonAncestor.cpp
 * @brief
 * @author   DuYong
 * @date     2021-03-08
 */

//===----------------------------- 递归版 ------------------------------===//
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    return root;
  }
};

//===----------------------------- 迭代版 ------------------------------===//
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    while (root) {
      if (root->val > p->val && root->val > q->val) {
        root = root->left;
      } else if (root->val < p->val && root->val < q->val) {
        root = root->right;
      } else {
        return root;
      }
    }
    return nullptr;
  }
};
