/**
 * @file     lc_0098.cpp
 * @brief    https://leetcode-cn.com/problems/validate-binary-search-tree/
 * @author   YongDu
 * @date     2021-09-09
 */
//===------------------------- [Recursive] --------------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  TreeNode *preNode = nullptr;

  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    bool leftIsValid = isValidBST(root->left);
    if (preNode != nullptr && root->val <= preNode->val) {
      return false;
    }
    preNode = root;
    bool rightIsValid = isValidBST(root->right);
    return leftIsValid && rightIsValid;
  }
};

//===------------------------- [Iterative] --------------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  bool isValidBST(TreeNode *root) {
    TreeNode *curNode = root;
    TreeNode *preNode = nullptr;
    std::stack<TreeNode *> stk;
    while (curNode || !stk.empty()) {
      if (curNode) {
        stk.push(curNode);
        curNode = curNode->left;
      } else {
        curNode = stk.top();
        stk.pop();
        if (preNode != nullptr && curNode->val <= preNode->val) {
          return false;
        }
        preNode = curNode;
        curNode = curNode->right;
      }
    }
    return true;
  }
};
