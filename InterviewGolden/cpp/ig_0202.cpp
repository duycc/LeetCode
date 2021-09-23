/**
 * @file     ig_0202.cpp
 * @brief    https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
 * @author   YongDu
 * @date     2021-09-11
 */

class Solution {
public:
  int kthToLast(ListNode *head, int k) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (--k) {
      fast = fast->next;
    }
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow->val;
  }
};
