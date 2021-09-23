/**
 * @file     lc_0206.cpp
 * @brief    https://leetcode-cn.com/problems/reverse-linked-list/
 * @author   YongDu
 * @date     2021-09-08
 */

/*----- 递归版 -----*/
class Solution {
public:
  ListNode *reverseList(ListNode *head) { return reverseList(nullptr, head); }

private:
  ListNode *reverseList(ListNode *preNode, ListNode *curNode) {
    if (nullptr == curNode) {
      return preNode;
    }
    ListNode *nextNode = curNode->next;
    curNode->next = preNode;
    return reverseList(curNode, nextNode);
  }
};

/*----- 迭代版 -----*/
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    // 迭代
    ListNode *preNode = nullptr;
    ListNode *curNode = nullptr;
    ListNode *tmpNode = head; // 一般不直接操作 head 头结点

    while (tmpNode) {
      curNode = tmpNode;
      tmpNode = tmpNode->next;
      curNode->next = preNode;
      preNode = curNode;
    }
    return curNode;
  }
};
