/**
 * @file     lc_0061.cpp
 * @brief    https://leetcode-cn.com/problems/rotate-list/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (k == 0 || head == nullptr) {
      return head;
    }
    int len = 0;
    ListNode *node = head;
    while (node) {
      len++;
      node = node->next;
    }
    k %= len;
    if (k == 0) {
      return head;
    }

    ListNode *left = head;
    ListNode *right = head;
    while (k--) {
      right = right->next;
    }
    while (right->next) {
      right = right->next;
      left = left->next;
    }
    right->next = head;
    head = left->next;
    left->next = nullptr;
    return head;
  }
};
