/**
 * @file     lc_1038.cpp
 * @brief    https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
 * @author   YongDu
 * @date     2021-10-03
 */
//===----------------------------- 递归版 ------------------------------===//
class Solution {
public:
  int preVal{0};

  TreeNode *bstToGst(TreeNode *root) {
    if (root) {
      bstToGst(root->right);
      root->val += preVal;
      preVal = root->val;
      bstToGst(root->left);
    }
    return root;
  }
};

//===----------------------------- 迭代版 ------------------------------===//
class Solution {
public:
  TreeNode *bstToGst(TreeNode *root) {
    std::stack<TreeNode *> stk;
    TreeNode *node = root;
    int preVal = 0;

    while (node || !stk.empty()) {
      if (node) {
        stk.push(node);
        node = node->right;
      } else {
        node = stk.top();
        stk.pop();
        node->val += preVal;
        preVal = node->val;
        node = node->left;
      }
    }
    return root;
  }
};
