/**
 * @file     lc_0437.cpp
 * @brief    https://leetcode-cn.com/problems/path-sum-iii/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return paths;
    }
    traversal(root, targetSum);
    (void)pathSum(root->left, targetSum);
    (void)pathSum(root->right, targetSum);
    return paths;
  }

private:
  int paths{0};

  void traversal(TreeNode *root, int curSum) {
    if (root == nullptr) {
      return;
    }
    curSum -= root->val;
    if (curSum == 0) {
      paths++;
    }
    traversal(root->left, curSum);
    traversal(root->right, curSum);
  }
};
