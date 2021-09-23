/**
 * @file     lc_0104.cpp
 * @brief    https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (nullptr == root)
      return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

// 层序遍历版
class Solution {
public:
  int maxDepth(TreeNode *root) {
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
