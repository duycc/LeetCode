/**
 * @file     jz_007.cpp
 * @brief    https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
 * @author   YongDu
 * @date     2021-10-16
 */

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) {
      return NULL;
    }
    return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int preBegin, int preEnd, int inBegin, int inEnd) {
    if (preBegin > preEnd || inBegin > inEnd) {
      return NULL;
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
