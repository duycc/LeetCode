/**
 * @file     lc_0429.cpp
 * @brief    https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
 * @author   YongDu
 * @date     2021-09-12
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;
    if (nullptr == root) {
      return result;
    }
    std::queue<Node *> que;
    Node *node = root;
    que.emplace(node);
    while (!que.empty()) {
      int size = que.size();
      vector<int> layerNodes;
      for (int i = 0; i < size; ++i) {
        node = que.front();
        que.pop();
        layerNodes.emplace_back(node->val);
        for (auto *child : node->children) {
          que.emplace(child);
        }
      }
      result.emplace_back(std::move(layerNodes));
    }
    return result;
  }
};
