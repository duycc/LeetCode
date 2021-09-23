/**
 * @file     lc_0141.cpp
 * @brief    https://leetcode-cn.com/problems/linked-list-cycle/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) {
      return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    do {
      if (!fast || !fast->next) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    } while (fast != slow);

    return true;
  }
};
