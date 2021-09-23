/**
 * @file     lc_0107.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * @author   YongDu
 * @date     2021-09-09
 */
class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if (nullptr == root) {
      return result;
    }
    std::queue<TreeNode *> que;
    TreeNode *node = root;
    que.emplace(node);
    while (!que.empty()) {
      int size = que.size();
      vector<int> layerNodes;
      while (size--) {
        node = que.front();
        layerNodes.emplace_back(node->val);
        que.pop();
        if (node->left) {
          que.emplace(node->left);
        }
        if (node->right) {
          que.emplace(node->right);
        }
      }
      result.insert(result.begin(), std::move(layerNodes));
    }
    return result;
  }
};
