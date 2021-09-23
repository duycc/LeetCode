/**
 * @file     lc_0938.cpp
 * @brief    https://leetcode-cn.com/problems/range-sum-of-bst/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
private:
  int sum = 0;

public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    if (root) {
      rangeSumBST(root->left, low, high);
      if (root->val >= low && root->val <= high) {
        sum += root->val;
      }
      rangeSumBST(root->right, low, high);
    }
    return sum;
  }
};
