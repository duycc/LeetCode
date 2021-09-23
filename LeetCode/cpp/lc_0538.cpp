/**
 * @file     lc_0538.cpp
 * @brief    https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 * @author   YongDu
 * @date     2021-09-09
 */

/*----- 递归版 -----*/
class Solution {
public:
  TreeNode *convertBST(TreeNode *root) { // 逆中序遍历，preNodeVal记录访问前一个节点的值
    if (nullptr == root) {
      return nullptr;
    }
    convertBST(root->right);
    root->val += preNodeVal;
    preNodeVal = root->val;
    convertBST(root->left);
    return root;
  }

private:
  int preNodeVal{0};
};

/*----- 迭代版 -----*/
class Solution {
public:
  TreeNode *convertBST(TreeNode *root) {
    if (nullptr == root) {
      return nullptr;
    }
    std::stack<TreeNode *> stk;
    int preNodeVal{0};
    TreeNode *curNode = root;
    while (curNode || !stk.empty()) {
      if (curNode) {
        stk.push(curNode);
        curNode = curNode->right;
      } else {
        curNode = stk.top();
        stk.pop();
        curNode->val += preNodeVal;
        preNodeVal = curNode->val;
        curNode = curNode->left;
      }
    }
    return root;
  }
};
