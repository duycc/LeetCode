/**
 * @file     lc_0023.cpp
 * @brief    https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * @author   DuYong
 * @date     2021-03-06
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
    struct lesser {
        bool operator()(const ListNode* lhs, const ListNode* rhs) { return lhs->val > rhs->val; }
    };

  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* pTmp = dummy;

        std::priority_queue<ListNode*, vector<ListNode*>, lesser> pque;
        for (auto& lst : lists) {
            if (lst) {
                pque.push(lst);
            }
        }

        while (!pque.empty()) {
            pTmp->next = pque.top();
            pque.pop();
            pTmp = pTmp->next;
            if (pTmp->next) {
                pque.push(pTmp->next);
            }
        }
        return dummy->next;
    }
};
