/**
 * @file     lc_0103.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 * @author   YongDu
 * @date     2021-10-03
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }
        std::queue<TreeNode*> que;
        TreeNode* node = root;
        que.push(node);
        bool needReverse = false;
        while (!que.empty()) {
            int size = que.size();
            std::vector<int> layerNodes;
            while (size--) {
                node = que.front();
                que.pop();
                layerNodes.push_back(node->val);
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
