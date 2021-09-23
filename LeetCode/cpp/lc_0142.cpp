/**
 * @file     lc_0142.cpp
 * @brief    https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * @author   YongDu
 * @date     2021-09-08
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    do {
      if (!fast || !fast->next) {
        return nullptr;
      }
      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);

    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
