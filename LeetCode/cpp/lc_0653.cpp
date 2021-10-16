/**
 * @file     lc_0653.cpp
 * @brief    https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
 * @author   YongDu
 * @date     2021-10-17
 */
//===------------------------- [hashSet + DFS] ----------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  bool findTarget(TreeNode *root, int k) {
    if (root == nullptr) {
      return false;
    }
    bool leftFind = findTarget(root->left, k);
    if (numSet.find(k - root->val) != numSet.end()) {
      return true;
    }
    numSet.emplace(root->val);
    bool rightFind = findTarget(root->right, k);
    return leftFind || rightFind;
  }

private:
  std::unordered_set<int> numSet;
};
