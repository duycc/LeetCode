/**
 * @file     lc_0117.cpp
 * @brief    https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
 * @author   YongDu
 * @date     2021-09-12
 */
/*
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
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* dummy = new Node();
        Node* prev = nullptr;
        Node* curr = root;
        while (curr != nullptr) {
            dummy->next = nullptr;
            prev = dummy;
            while (curr != nullptr) {
                if (curr->left) {
                    prev->next = curr->left;
                    prev = prev->next;
                }
                if (curr->right) {
                    prev->next = curr->right;
                    prev = prev->next;
                }
                curr = curr->next;
            }
            curr = dummy->next;
        }
        return root;
    }
};
