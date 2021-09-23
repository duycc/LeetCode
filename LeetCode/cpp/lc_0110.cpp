/**
 * @file     lc_0110.cpp
 * @brief    https://leetcode-cn.com/problems/balanced-binary-tree/
 * @author   YongDu
 * @date     2021-09-09
 */
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (nullptr == root)
      return true;

#if 0
        // 1. 遍历左右子树高度
        return (abs(level(root->left) - level(root->right)) < 2) &&
                isBalanced(root->left) && isBalanced(root->right);
#endif

    // 2. 一种更好的解决办法
    return isBalancedHelper(root) != -1;
  }

  int level(TreeNode *root) {
    if (nullptr == root)
      return 0;
    return max(level(root->left), level(root->right)) + 1;
  }

  int isBalancedHelper(TreeNode *root) {
    if (nullptr == root)
      return 0;

    int leftHeight = isBalancedHelper(root->left);
    if (leftHeight == -1)
      return -1;

    int rightHeight = isBalancedHelper(root->right);
    if (rightHeight == -1)
      return -1;

    if (abs(leftHeight - rightHeight) > 1)
      return -1;

    return max(leftHeight, rightHeight) + 1;
  }
};
