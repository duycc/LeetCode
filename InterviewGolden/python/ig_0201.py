"""
 * @file     removeDuplicateNodes.py
 * @brief    https://leetcode-cn.com/problems/remove-duplicate-node-lcci/
 * @author   YongDu
 * @date     2021-08-18
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        ptmp = head
        exist = [False for i in range(20000)]
        while ptmp and ptmp.next:
            exist[ptmp.val] = True
            if exist[ptmp.next.val]:
                ptmp.next = ptmp.next.next
            else:
                ptmp = ptmp.next
        return head
