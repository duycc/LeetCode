/**
 * @file     lc_0100.cpp
 * @brief    https://leetcode-cn.com/problems/same-tree/
 * @author   YongDu
 * @date     2021-10-02
 */
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
