/**
 * @file     lc_0111.cpp
 * @brief    https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left != nullptr && root->right != nullptr) {
      return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    return std::max(minDepth(root->left), minDepth(root->right)) + 1;
  }
};

// 层序遍历版
class Solution {
public:
  int minDepth(TreeNode *root) {
    if (nullptr == root) {
      return 0;
    }
    int depth = 0;
    std::queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      depth++;
      while (size--) {
        TreeNode *node = que.front();
        que.pop();
        if (!node->left && !node->right) { // 当左右孩子皆为空，到达最小深度
          return depth;
        }
        if (node->left) {
          que.emplace(node->left);
        }
        if (node->right) {
          que.emplace(node->right);
        }
      }
    }
    return depth;
  }
};
