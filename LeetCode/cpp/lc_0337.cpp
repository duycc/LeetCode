/**
 * @file     lc_0337.cpp
 * @brief    https://leetcode-cn.com/problems/house-robber-iii/
 * @author   YongDu
 * @date     2021-11-01
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int rob(TreeNode *root) {
    // 树形dp
    auto &&result = robTree(root);
    return std::max(result[0], result[1]);
  }

private:
  vector<int> robTree(TreeNode *root) {
    if (root == nullptr) {
      return vector<int>{0, 0};
    }
    vector<int> left = robTree(root->left);
    vector<int> right = robTree(root->right);
    // 偷root
    int val1 = root->val + left[0] + right[0];
    // 不偷root
    int val2 = std::max(left[0], left[1]) + std::max(right[0], right[1]);
    return vector<int>{val2, val1};
  }
};
