/**
 * @file     lc_0117.cpp
 * @brief    https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
 * @author   YongDu
 * @date     2021-09-12
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
  Node *connect(Node *root) {
    if (nullptr == root) {
      return nullptr;
    }
    std::queue<Node *> que;
    Node *curNode;
    Node *preNode;
    que.emplace(root);
    while (!que.empty()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        if (0 == i) {
          preNode = que.front();
          que.pop();
          curNode = preNode; // 不要忘记
        } else {
          curNode = que.front();
          que.pop();
          preNode->next = curNode;
          preNode = curNode;
        }
        if (curNode->left) {
          que.emplace(curNode->left);
        }
        if (curNode->right) {
          que.emplace(curNode->right);
        }
      }
      curNode->next = nullptr;
    }
    return root;
  }
};
