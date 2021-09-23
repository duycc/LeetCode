/**
 * @file     lc_0113.cpp
 * @brief    https://leetcode-cn.com/problems/path-sum-ii/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
private:
  vector<vector<int>> result;
  vector<int> path;

  // 遍历整棵树，不需要返回值
  void traversal(TreeNode *root, int count) {
    if (!root->left && !root->right && count == 0) {
      result.emplace_back(path);
      return;
    }
    if (!root->left && !root->right)
      return;

    if (root->left) {
      path.emplace_back(root->left->val);
      traversal(root->left, count - root->left->val);
      path.pop_back();
    }
    if (root->right) {
      path.emplace_back(root->right->val);
      traversal(root->right, count - root->right->val);
      path.pop_back();
    }

    return;
  }

public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (nullptr == root)
      return result;

    path.emplace_back(root->val);
    traversal(root, targetSum - root->val);

    return result;
  }
};
