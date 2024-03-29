/**
 * @file     lc_0538.cpp
 * @brief    https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 * @author   YongDu
 * @date     2021-09-09
 */

/*----- 递归版 -----*/
class Solution {
public:
  int preVal{0};

  TreeNode *convertBST(TreeNode *root) {
    if (root) {
      convertBST(root->right);
      root->val += preVal;
      preVal = root->val;
      convertBST(root->left);
    }
    return root;
  }
};

/*----- 迭代版 -----*/
class Solution {
public:
  TreeNode *convertBST(TreeNode *root) {
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
