/**
 * @file     lc_0206.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-linked-list/
 * @author   YongDu
 * @date     2021-09-08
 */

/*----- 递归版 -----*/
class Solution {
  public:
    ListNode* reverseList(ListNode* head) { return reverseList(nullptr, head); }

  private:
    ListNode* reverseList(ListNode* preNode, ListNode* curNode) {
        if (nullptr == curNode) {
            return preNode;
        }
        ListNode* nextNode = curNode->next;
        curNode->next = preNode;
        return reverseList(curNode, nextNode);
    }
};

/*----- 迭代版 -----*/
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        while (head) {
            curr = head;
            head = head->next;
            curr->next = prev;
            prev = curr;
        }
        head = curr;
        return head;
    }
};