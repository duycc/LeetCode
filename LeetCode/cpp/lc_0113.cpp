/**
 * @file     lc_0113.cpp
 * @brief    https://leetcode-cn.com/problems/path-sum-ii/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return result;
    }
    path.emplace_back(root->val);
    traversal(root, targetSum - root->val);
    return result;
  }

private:
  vector<vector<int>> result;
  vector<int> path;

  void traversal(const TreeNode *root, int currTarget) {
    if ((root->left == nullptr && root->right == nullptr) && currTarget == 0) {
      result.emplace_back(path);
      return;
    }
    if (root->left) {
      path.emplace_back(root->left->val);
      traversal(root->left, currTarget - root->left->val);
      path.pop_back();
    }
    if (root->right) {
      path.emplace_back(root->right->val);
      traversal(root->right, currTarget - root->right->val);
      path.pop_back();
    }
  }
};
