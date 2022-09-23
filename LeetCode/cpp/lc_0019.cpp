/**
 * @file     lc_0019.cpp
 * @brief    https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * @author   YongDu
 * @date     2021-09-08
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;

        ListNode* leftNode = dummyNode;
        ListNode* rightNode = dummyNode;
        while (n--) {
            rightNode = rightNode->next;
        }

        while (rightNode->next) {
            rightNode = rightNode->next;
            leftNode = leftNode->next;
        }

        ListNode* tmpNode = leftNode->next;
        leftNode->next = leftNode->next->next;
        head = dummyNode->next;
        delete tmpNode;
        delete dummyNode;
        return head;
    }
};
