/**
 * @file     lc_0968.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-cameras/
 * @author   YongDu
 * @date     2021-10-18
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
  int minCameraCover(TreeNode *root) {
    if (traversal(root) == 0) {
      minCamer++;
    }
    return minCamer;
  }

private:
  int minCamer = 0;

  int traversal(TreeNode *root) {
    // 空节点，有覆盖
    if (root == nullptr) {
      return 2;
    }
    int left = traversal(root->left);
    int right = traversal(root->right);

    // 左右都覆盖
    if (left == 2 && right == 2) {
      return 0;
    }

    // 左右存在无覆盖
    if (left == 0 || right == 0) {
      minCamer++;
      return 1;
    }

    // 左右有相机
    if (left == 1 || right == 1) {
      return 2;
    }
    return -1; // 该语句不可达
  }
};
