/**
 * @file     lc_0108.cpp
 * @brief    https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
 * @author   YongDu
 * @date     2021-09-08
 */
/*----- 递归版 -----*/
class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }
    return buildRecursive(nums, 0, nums.size() - 1);
  }

private:
  TreeNode *buildRecursive(vector<int> &nums, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = left + ((right - left) >> 1);
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildRecursive(nums, left, mid - 1);
    root->right = buildRecursive(nums, mid + 1, right);
    return root;
  }
};

/*----- 迭代版 -----*/
class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }

    std::queue<TreeNode *> nodeQueue;
    std::queue<std::pair<int, int>> rangeQueue;
    TreeNode *root = new TreeNode(0);
    nodeQueue.emplace(root);
    rangeQueue.emplace(std::make_pair(0, nums.size() - 1));

    while (!nodeQueue.empty()) {
      TreeNode *curNode = nodeQueue.front();
      nodeQueue.pop();
      int left = rangeQueue.front().first;
      int right = rangeQueue.front().second;
      rangeQueue.pop();

      int mid = left + ((right - left) >> 1);
      curNode->val = nums[mid];

      if (left <= mid - 1) {
        curNode->left = new TreeNode(0);
        nodeQueue.emplace(curNode->left);
        rangeQueue.emplace(std::make_pair(left, mid - 1));
      }

      if (right >= mid + 1) {
        curNode->right = new TreeNode(0);
        nodeQueue.emplace(curNode->right);
        rangeQueue.emplace(std::make_pair(mid + 1, right));
      }
    }
    return root;
  }
};
