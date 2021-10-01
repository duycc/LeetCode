/**
 * @file     lc_0222.cpp
 * @brief    https://leetcode-cn.com/problems/count-complete-tree-nodes/
 * @author   YongDu
 * @date     2021-10-02
 */
class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
