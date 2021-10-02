/**
 * @file     lc_0654.cpp
 * @brief    https://leetcode-cn.com/problems/maximum-binary-tree/
 * @author   YongDu
 * @date     2021-10-03
 */

class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }
    return buildTree(nums, 0, nums.size() - 1);
  }

private:
  TreeNode *buildTree(vector<int> &nums, int begin, int end) {
    if (begin > end) {
      return nullptr;
    }
    int maxIdx = begin;
    for (int i = begin; i <= end; ++i) {
      if (nums[i] > nums[maxIdx]) {
        maxIdx = i;
      }
    }
    TreeNode *root = new TreeNode(nums[maxIdx]);
    if (begin == end) {
      return root;
    }
    root->left = buildTree(nums, begin, maxIdx - 1);
    root->right = buildTree(nums, maxIdx + 1, end);
    return root;
  }
};
