/**
 * @file     lc_0103.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 * @author   YongDu
 * @date     2021-10-03
 */
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }
    std::queue<TreeNode *> que;
    que.push(root);
    bool needReverse{false};

    while (!que.empty()) {
      int size = que.size();
      vector<int> layerNodes;
      while (size--) {
        TreeNode *node = que.front();
        que.pop();
        layerNodes.emplace_back(node->val);
        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
      if (needReverse) {
        std::reverse(layerNodes.begin(), layerNodes.end());
      }
      needReverse = !needReverse;
      result.emplace_back(layerNodes);
    }
    return result;
  }
};
