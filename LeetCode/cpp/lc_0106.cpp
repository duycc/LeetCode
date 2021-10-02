/**
 * @file     lc_0106.cpp
 * @brief    https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty() || postorder.empty()) {
      return nullptr;
    }
    return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inBegin, int inEnd, int postBegin,
                      int postEnd) {
    if (inBegin > inEnd || postBegin > postEnd) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(postorder[postEnd]);
    if (inBegin == inEnd) {
      return root;
    }
    int mid = inBegin;
    while (mid <= inEnd && inorder[mid] != postorder[postEnd]) {
      mid++;
    }
    int leftCount = mid - inBegin;
    root->left = buildTree(inorder, postorder, inBegin, mid - 1, postBegin, postBegin + leftCount - 1);
    root->right = buildTree(inorder, postorder, mid + 1, inEnd, postBegin + leftCount, postEnd - 1);
    return root;
  }
};
