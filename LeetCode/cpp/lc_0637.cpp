/**
 * @file     lc_0637.cpp
 * @brief    https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
 * @author   YongDu
 * @date     2021-09-12
 */

class Solution {
  public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (nullptr == root) {
            return result;
        }
        std::queue<TreeNode*> que;
        TreeNode* node = root;
        que.emplace(node);
        while (!que.empty()) {
            int size = que.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) {
                    que.emplace(node->left);
                }
                if (node->right) {
                    que.emplace(node->right);
                }
            }
            result.emplace_back(sum / size);
        }
        return result;
    }
};
