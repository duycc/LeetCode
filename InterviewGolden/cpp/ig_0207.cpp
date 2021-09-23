/**
 * @file     ig_0207.cpp
 * @brief    https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (nullptr == headA || nullptr == headB) {
      return nullptr;
    }
    int lenA = 0;
    int lenB = 0;
    ListNode *curA = headA;
    ListNode *curB = headB;

    while (curA) {
      lenA++;
      curA = curA->next;
    }
    while (curB) {
      lenB++;
      curB = curB->next;
    }

    curA = headA; // 记得重置结点
    curB = headB;

    if (lenB > lenA) {
      std::swap(lenA, lenB);
      std::swap(curA, curB);
    }

    int gap = lenA - lenB;
    while (gap--) {
      curA = curA->next;
    }

    while (curA) {
      if (curA == curB) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }
    return nullptr;
  }
};
