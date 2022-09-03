/**
 * @file     deleteNode.cpp
 * @brief    https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * @author   DuYong
 * @date     2021-03-06
 */
class Solution {
  public:
    void deleteNode(ListNode* node) {
        ListNode* delNode = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete delNode;
        return;
    }
};
