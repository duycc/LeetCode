/**
 * @file     lc_0112.cpp
 * @brief    https://leetcode-cn.com/problems/path-sum/
 * @author   YongDu
 * @date     2021-09-10
 */

//===----------------------------- 递归 ------------------------------===//
class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (root->val == targetSum && (root->left == nullptr && root->right == nullptr)) {
      return true;
    }
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
  }
};

//===----------------------------- 迭代 ------------------------------===//
class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    std::stack<std::pair<TreeNode *, int>> stk; // <node, pathSum>
    stk.push(std::make_pair(root, root->val));
    std::pair<TreeNode *, int> node;
    while (!stk.empty()) {
      node = stk.top();
      stk.pop();
      if (node.second == targetSum && (node.first->left == nullptr && node.first->right == nullptr)) {
        return true;
      }
      if (node.first->left) {
        stk.push(std::make_pair(node.first->left, node.second + node.first->left->val));
      }
      if (node.first->right) {
        stk.push(std::make_pair(node.first->right, node.second + node.first->right->val));
      }
    }
    return false;
  }
};
