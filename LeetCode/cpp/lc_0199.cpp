/**
 * @file     lc_0199.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-right-side-view/
 * @author   YongDu
 * @date     2021-09-12
 */

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    if (nullptr == root) {
      return result;
    }

    std::queue<TreeNode *> que;
    TreeNode *node = root;
    que.emplace(node);

    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        node = que.front();
        que.pop();
        if (i == size - 1) {
          result.emplace_back(node->val);
        }
        if (node->left) {
          que.emplace(node->left);
        }
        if (node->right) {
          que.emplace(node->right);
        }
      }
    }
    return result;
  }
};
