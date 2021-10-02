/**
 * @file     lc_0105.cpp
 * @brief    https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty()) {
      return nullptr;
    }
    if (preorder.size() != inorder.size()) {
      return nullptr;
    }
    return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
    if (preBegin > preEnd || inBegin > inEnd) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[preBegin]);
    if (preBegin == preEnd) {
      return root;
    }
    int mid = inBegin;
    while (mid <= inEnd && inorder[mid] != preorder[preBegin]) {
      mid++;
    }
    int leftCount = mid - inBegin;
    root->left = buildTree(preorder, inorder, preBegin + 1, preBegin + leftCount, inBegin, mid - 1);
    root->right = buildTree(preorder, inorder, preBegin + leftCount + 1, preEnd, mid + 1, inEnd);
    return root;
  }
};
