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
    vector<vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }
        std::queue<Node*> que;
        Node* node = root;
        que.push(node);
        while (!que.empty()) {
            int size = que.size();
            std::vector<int> layerNodes;
            while (size--) {
                node = que.front();
                que.pop();
                layerNodes.push_back(node->val);
                for (auto* child : node->children) {
                    que.push(child);
                }
            }
            result.emplace_back(layerNodes);
        }
        return result;
    }
};
