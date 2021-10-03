/**
 * @file     lc_0108.cpp
 * @brief    https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
 * @author   YongDu
 * @date     2021-09-08
 */
//===----------------------------- 递归版 ------------------------------===//
class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }
    return buildTree(nums, 0, nums.size() - 1);
  }

private:
  TreeNode *buildTree(const vector<int> &nums, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int mid = begin + ((end - begin) >> 1);
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, begin, mid - 1);
    root->right = buildTree(nums, mid + 1, end);
    return root;
  }
};
