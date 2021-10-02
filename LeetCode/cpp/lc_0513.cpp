/**
 * @file     lc_0513.cpp
 * @brief    https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 * @author   YongDu
 * @date     2021-10-02
 */
//===----------------------------- 层序遍历，最后一层第一个节点 ------------------------------===//
class Solution {
public:
  int findBottomLeftValue(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    std::queue<TreeNode *> que;
    int leftDown{0};
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = que.front();
        que.pop();
        if (i == 0) {
          leftDown = node->val;
        }
        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
    }
    return leftDown;
  }
};
