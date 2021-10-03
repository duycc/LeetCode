/**
 * @file     lc_0501.cpp
 * @brief    https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 * @author   YongDu
 * @date     2021-10-03
 */
//===----------------------------- 二叉搜索树，中序递归 ------------------------------===//
class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    TreeNode *preNode = nullptr;
    int count{0};
    int maxCount{0};
    vector<int> result;

    std::function<void(TreeNode *)> traversal = [&](TreeNode *curNode) {
      if (curNode == nullptr) {
        return;
      }
      traversal(curNode->left);
      if (preNode == nullptr) {
        count = 1;
      } else if (curNode->val == preNode->val) { // 与前一个节点相等
        count++;
      } else { // 与前一个节点不相等
        count = 1;
      }
      preNode = curNode; // 更新 preNode

      if (count == maxCount) {
        result.emplace_back(curNode->val);
      }
      if (count > maxCount) {
        maxCount = count;
        result.clear(); // 如果当前count大于maxCount，前面收集的result无效，需清空
        result.emplace_back(curNode->val);
      }
      traversal(curNode->right);
    };

    traversal(root);
    return result;
  }
};

//===----------------------------- 迭代版 ------------------------------===//
class Solution {
public:
  vector<int> findMode(TreeNode *root) {
    TreeNode *curNode = root;
    TreeNode *preNode = nullptr;
    std::stack<TreeNode *> stk;
    vector<int> result;
    int count{0};
    int maxCount{0};

    while (curNode || !stk.empty()) {
      if (curNode) {
        stk.push(curNode);
        curNode = curNode->left;
      } else {
        curNode = stk.top();
        stk.pop();
        if (preNode == nullptr) {
          count = 1;
        } else if (curNode->val == preNode->val) {
          count++;
        } else {
          count = 1;
        }
        if (count == maxCount) {
          result.emplace_back(curNode->val);
        }
        if (count > maxCount) {
          maxCount = count;
          result.clear();
          result.emplace_back(curNode->val);
        }
        preNode = curNode;
        curNode = curNode->right;
      }
    }
    return result;
  }
};
