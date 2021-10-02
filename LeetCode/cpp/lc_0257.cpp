/**
 * @file     binaryTreePaths.cpp
 * @brief    https://leetcode-cn.com/problems/binary-tree-paths/
 * @author   DuYong
 * @date     2021-03-07
 */
//===----------------------------- 回溯 ------------------------------===//
class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    if (root == nullptr) {
      return result;
    }
    traversal(root);
    return result;
  }

private:
  vector<string> result;
  vector<int> path;

  void traversal(const TreeNode *root) {
    path.emplace_back(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      string strPath;
      for (int i = 0; i < path.size() - 1; ++i) {
        strPath += std::to_string(path[i]) + "->";
      }
      strPath += std::to_string(path[path.size() - 1]);
      result.emplace_back(std::move(strPath));
      return;
    }
    if (root->left) {
      traversal(root->left);
      path.pop_back();
    }
    if (root->right) {
      traversal(root->right);
      path.pop_back();
    }
  }
};

//===----------------------------- 简化版回溯 ------------------------------===//
class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    if (root == nullptr) {
      return result;
    }
    string path;
    traversal(root, result, path);
    return result;
  }

private:
  void traversal(const TreeNode *root, vector<string> &result, string path) {
    path += std::to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      result.emplace_back(path);
      return;
    }
    if (root->left) {
      traversal(root->left, result, path + "->");
    }
    if (root->right) {
      traversal(root->right, result, path + "->");
    }
  }
};

//===----------------------------- 迭代 ------------------------------===//
class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> result;
    if (root == nullptr) {
      return result;
    }
    std::stack<TreeNode *> nodeStk;
    std::stack<string> pathStk;
    nodeStk.push(root);
    pathStk.push(std::to_string(root->val));

    while (!nodeStk.empty()) {
      TreeNode *node = nodeStk.top();
      nodeStk.pop();
      string path = pathStk.top();
      pathStk.pop();
      if (node->left == nullptr && node->right == nullptr) {
        result.emplace_back(std::move(path));
      }
      if (node->right) {
        nodeStk.push(node->right);
        pathStk.push(path + "->" + std::to_string(node->right->val));
      }
      if (node->left) {
        nodeStk.push(node->left);
        pathStk.push(path + "->" + std::to_string(node->left->val));
      }
    }
    return result;
  }
};
