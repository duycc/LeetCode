/**
 * @file     lc_0024.cpp
 * @brief    https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 * @author   YongDu
 * @date     2021-09-08
 */
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummyNode = new ListNode();
    dummyNode->next = head;
    ListNode *preNode = dummyNode;
    ListNode *leftNode = head;
    ListNode *rightNode = nullptr;

    while (leftNode && leftNode->next) {
      rightNode = leftNode->next;
      preNode->next = rightNode;
      leftNode->next = rightNode->next;
      rightNode->next = leftNode;
      preNode = leftNode;
      leftNode = leftNode->next;
    }

    head = dummyNode->next;
    delete dummyNode;
    return head;
  }
};
