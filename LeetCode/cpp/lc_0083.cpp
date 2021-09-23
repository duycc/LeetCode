/**
 * @file     lc_0083.cpp
 * @brief    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *pTmp = head;

    while (pTmp && pTmp->next) {
      if (pTmp->next->val == pTmp->val) {
        pTmp->next = pTmp->next->next;
      } else {
        pTmp = pTmp->next;
      }
    }

    return head;
  }
};
