/**
 * @file     lc_0404.cpp
 * @brief    https://leetcode-cn.com/problems/sum-of-left-leaves/
 * @author   YongDu
 * @date     2021-10-02
 */
//===----------------------------- 普通递归 ------------------------------===//
class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int sum = 0;
    traversal(root, sum);
    return sum;
  }

private:
  void traversal(const TreeNode *root, int &sum) {
    if (root->left) {
      if (root->left->left == nullptr && root->left->right == nullptr) {
        sum += root->left->val;
      }
      traversal(root->left, sum);
    }
    if (root->right) {
      traversal(root->right, sum);
    }
  }
};

//===----------------------------- 简化逻辑 ------------------------------===//
class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int currVal{0};
    if (root->left && (root->left->left == nullptr && root->left->right == nullptr)) {
      currVal = root->left->val;
    }
    return currVal + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};

//===----------------------------- 迭代版 ------------------------------===//
class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    std::stack<TreeNode *> stk;
    stk.push(root);
    int result{0};
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      stk.pop();
      if (node->left && (node->left->left == nullptr && node->left->right == nullptr)) {
        result += node->left->val;
      }
      if (node->right) {
        stk.push(node->right);
      }
      if (node->left) {
        stk.push(node->left);
      }
    }
    return result;
  }
};
