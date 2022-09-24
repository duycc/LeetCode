/**
 * @file     lc_0145.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * @author   YongDu
 * @date     2021-09-09
 */
class Solution {
  public:
    vector<int> result; // 结果集

    vector<int> postorderTraversal(TreeNode* root) {
        if (nullptr == root)
            return result;

#if 0
        // 1. 递归版
        if(root) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.emplace_back(root->val);
        }
        return result;
#endif

        // 2. 迭代版
        stack<TreeNode*> stk;
        TreeNode* node = root;
        stk.push(node);
        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
            result.emplace_back(node->val);
            if (node->left)
                stk.push(node->left);
            if (node->right)
                stk.push(node->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
