/**
 * @file     lc_0143.cpp
 * @brief    https://leetcode-cn.com/problems/reorder-list/
 * @author   YongDu
 * @date     2021-10-12
 */

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next || !head->next->next) {
      return;
    }

    ListNode *midNode = middleNode(head);
    ListNode *right = reverseList(midNode->next);
    midNode->next = nullptr;
    mergeList(head, right);
  }

  ListNode *middleNode(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    while (head) {
      ListNode *curr = head;
      head = head->next;
      curr->next = prev;
      prev = curr;
    }

    return prev;
  }

  void mergeList(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode();

    while (left && right) {
      dummy->next = left;
      left = left->next;
      dummy = dummy->next;
      dummy->next = right;
      right = right->next;
      dummy = dummy->next;
    }

    dummy->next = left ? left : right;
  }
};
