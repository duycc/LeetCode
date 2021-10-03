/**
 * @file     lc_0783.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 * @author   YongDu
 * @date     2021-10-03
 */
class Solution {
public:
  int minDiffInBST(TreeNode *root) {
    TreeNode *preNode{nullptr};
    int minDiff{INT_MAX};

    std::function<void(TreeNode *)> traversal = [&](TreeNode *root) {
      if (root == nullptr) {
        return;
      }
      traversal(root->left);
      if (preNode) {
        minDiff = std::min(root->val - preNode->val, minDiff);
      }
      preNode = root;
      traversal(root->right);
    };

    traversal(root);
    return minDiff;
  }
};
