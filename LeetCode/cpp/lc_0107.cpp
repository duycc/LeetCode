/**
 * @file     lc_0107.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * @author   YongDu
 * @date     2021-09-09
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
    std::vector<std::vector<int>> result;

  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) {
            return result;
        }
        std::queue<TreeNode*> que;
        TreeNode* node = root;
        que.push(node);
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
            result.emplace_back(layerNodes);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
