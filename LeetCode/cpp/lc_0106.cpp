/**
 * @file     lc_0106.cpp
 * @brief    https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * @author   YongDu
 * @date     2021-09-10
 */

class Solution {
public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty() || postorder.empty())
      return nullptr;

    if (inorder.size() != postorder.size())
      return nullptr;

    int pos = inorder.size() - 1;
    return buildTree(inorder, postorder, 0, pos, 0, pos);
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart,
                      int postEnd) {
    if (inStart > inEnd || postStart > postEnd)
      return nullptr;

    TreeNode *root = new TreeNode(postorder[postEnd]);
    if (inStart == inEnd)
      return root;

    int mid = inStart;
    while (mid <= inEnd && inorder[mid] != postorder[postEnd]) {
      mid++;
    }

    int leftCount = mid - inStart;
    root->left = buildTree(inorder, postorder, inStart, mid - 1, postStart, postStart + leftCount - 1);
    root->right = buildTree(inorder, postorder, mid + 1, inEnd, postStart + leftCount, postEnd - 1);

    return root;
  }
};
