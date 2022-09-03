/**
 * @file     lc_0203.cpp
 * @brief    https://leetcode-cn.com/problems/remove-linked-list-elements/
 * @author   YongDu
 * @date     2021-09-08
 */

class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* curNode = dummyNode;
        while (curNode->next) {
            ListNode* tmpNode = curNode->next;
            if (tmpNode->val == val) {
                curNode->next = tmpNode->next;
                delete tmpNode;
            } else {
                curNode = curNode->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};
