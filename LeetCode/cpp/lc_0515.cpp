/**
 * @file     lc_0515.cpp
 * @brief    https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
 * @author   YongDu
 * @date     2021-09-12
 */

class Solution {
public:
  vector<int> largestValues(TreeNode *root) {
    vector<int> result;
    if (nullptr == root) {
      return result;
    }
    std::queue<TreeNode *> que;
    TreeNode *node = root;
    que.emplace(node);
    while (!que.empty()) {
      int size = que.size();
      int layerMax = INT_MIN;
      for (int i = 0; i < size; ++i) {
        node = que.front();
        que.pop();
        layerMax = std::max(layerMax, node->val);
        if (node->left) {
          que.emplace(node->left);
        }
        if (node->right) {
          que.emplace(node->right);
        }
      }
      result.emplace_back(layerMax);
    }
    return result;
  }
};
