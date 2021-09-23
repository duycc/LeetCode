/**
 * @file     lc_0203.cpp
 * @brief    https://leetcode-cn.com/problems/remove-linked-list-elements/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *curNode = dummyNode;

    while (curNode->next != nullptr) {
      if (curNode->next->val == val) {
        ListNode *tmp = curNode->next;
        curNode->next = curNode->next->next;
        delete tmp;
      } else {
        curNode = curNode->next;
      }
    }

    head = dummyNode->next;
    delete dummyNode;
    return head;
  }
};
