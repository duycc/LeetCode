/**
 * @file     lc_0110.cpp
 * @brief    https://leetcode-cn.com/problems/balanced-binary-tree/
 * @author   YongDu
 * @date     2021-09-09
 */
// 递归
class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return std::abs(getHight(root->left) - getHight(root->right)) < 2 && isBalanced(root->left) &&
           isBalanced(root->right);
  }

private:
  int getHight(const TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return std::max(getHight(root->left), getHight(root->right)) + 1;
  }
};

// 改进版递归
class Solution {
public:
  bool isBalanced(TreeNode *root) { return getDepth(root) == -1 ? false : true; }

private:
  int getDepth(const TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int leftDepth = getDepth(root->left);
    if (leftDepth == -1) {
      return -1;
    }
    int rightDepth = getDepth(root->right);
    if (rightDepth == -1) {
      return -1;
    }
    return std::abs(leftDepth - rightDepth) > 1 ? -1 : std::max(leftDepth, rightDepth) + 1;
  }
};
