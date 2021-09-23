/**
 * @file     lc_0082.cpp
 * @brief    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head) {
      return head;
    }

    ListNode *dummy = new ListNode(0, head);
    ListNode *node = dummy;
    while (node->next && node->next->next) {
      if (node->next->val == node->next->next->val) {
        int tmp = node->next->val;
        while (node->next && node->next->val == tmp) {
          ListNode *pTmp = node->next;
          node->next = node->next->next;
          delete pTmp;
        }
      } else {
        node = node->next;
      }
    }

    node = dummy->next;
    delete dummy;

    return node;
  }
};
