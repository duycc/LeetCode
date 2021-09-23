/**
 * @file     reverseList.js
 * @brief    [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)
 * @author   Zhu
 * @date     2021-08-10 22:41
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * 迭代 - head.next
 * 每次上头指针指向cur指针的next，直到null
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
    if (head == null) return null;
    let cur = head;
    while (head.next) {
        let temp = head.next.next;
        head.next.next = cur;
        cur = head.next;
        head.next = temp;
    }
    return cur;
};

/**
 * 迭代 - cur
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
    let pre = null;
    let cur = head;
    while (cur) {
        const next = cur.next;
        cur.next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
};

/**
 * 递归
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
    function recursive(cur, pre) {
        if (cur == null) return pre;
        let temp = cur.next;
        cur.next = pre;
        return recursive(temp, cur);
    }

    return recursive(head, null);
};

/**
 * 递归 - 回溯？
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
    if (head == null) return null;
    if (head.next == null) return head;
    let tail = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return tail;
};