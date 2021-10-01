/**
 * @file     lc_0559.cpp
 * @brief    https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
 * @author   YongDu
 * @date     2021-10-02
 */
class Solution {
public:
  int maxDepth(Node *root) {
    if (root == nullptr) {
      return 0;
    }
    int depth{0};
    for (auto *child : root->children) {
      depth = std::max(maxDepth(child), depth);
    }
    return depth + 1;
  }
};
