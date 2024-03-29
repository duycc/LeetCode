/**
 * @file     lc_0094.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * @author   YongDu
 * @date     2021-09-09
 */
class Solution {
  public:
    vector<int> result; // 结果集

    vector<int> inorderTraversal(TreeNode* root) {
        if (nullptr == root)
            return result;

#if 0
        // 1. 递归
        if(root) {
            inorderTraversal(root->left);
            result.emplace_back(root->val);
            inorderTraversal(root->right);
        }

        return result;
#endif

        // 2. 迭代
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                result.emplace_back(node->val);
                node = node->right;
            }
        }

        return result;
    }
};
