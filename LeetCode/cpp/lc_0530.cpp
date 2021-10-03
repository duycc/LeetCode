/**
 * @file     lc_0530.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * @author   YongDu
 * @date     2021-10-03
 */

//===----------------------------- 迭代版 ------------------------------===//
class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    TreeNode *preNode = nullptr;
    int minDiff = INT_MAX;

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

//===----------------------------- 递归版 ------------------------------===//

class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    getMinimumDifference(root->left);
    if (preNode) {
      minDiff = std::min(root->val - preNode->val, minDiff);
    }
    preNode = root;
    getMinimumDifference(root->right);
    return minDiff;
  }

private:
  int minDiff = INT_MAX;
  TreeNode *preNode = nullptr;
};
