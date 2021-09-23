/**
 * @file     ig_0201.cpp
 * @brief    https://leetcode-cn.com/problems/remove-duplicate-node-lcci/
 * @author   YongDu
 * @date     2021-09-09
 */

class Solution {
public:
  ListNode *removeDuplicateNodes(ListNode *head) {
    if (head == NULL) {
      return head;
    }

    vector<bool> exist(20000, false);
    ListNode *pTmp = head;
    while (pTmp && pTmp->next) {
      exist[pTmp->val] = true;
      if (exist[pTmp->next->val]) {
        pTmp->next = pTmp->next->next;
        // continue;
      } else {
        pTmp = pTmp->next;
      }
    }

    return head;
  }
};
