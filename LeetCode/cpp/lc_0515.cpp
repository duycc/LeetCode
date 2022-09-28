/**
 * @file     lc_0515.cpp
 * @brief    https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
 * @author   YongDu
 * @date     2021-09-12
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
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        std::queue<Node*> que;
        Node* node = root;
        que.push(node);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                node = que.front();
                que.pop();
                if (i < size - 1) {
                    node->next = que.front();
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};
