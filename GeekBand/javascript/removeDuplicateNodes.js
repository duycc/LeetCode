/**
 * @file     removeDuplicateNodes.js
 * @brief    https://leetcode-cn.com/problems/remove-duplicate-node-lcci/submissions/
 * @author   Zhu
 * @date     2021-07-26 14:12
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * 利用Set去重
 * @param {ListNode} head
 * @return {ListNode}
 */
var removeDuplicateNodes = function (head) {
    const nodeSet = new Set();
    let cur = head;
    let pre = head;
    while (cur) {
        if (nodeSet.has(cur.val)) {
            pre.next = cur.next;
        } else {
            nodeSet.add(cur.val);
            pre = cur;
        }
        cur = cur.next;
    }
    return head;
};

/**
 * O(n^2)
 * @param {ListNode} head
 * @return {ListNode}
 */
var removeDuplicateNodes = function (head) {
    let left = head;
    while (left) {
        let pre = left;
        let right = left.next;
        while (right) {
            if (left.val === right.val) {
                pre.next = right.next;
            } else {
                pre = right;
            }
            right = right.next;
        }
        left = left.next;
    }

    return head;
};

/**
 * 稍微改进，直接while(cur.next)
 * @param {ListNode} head
 * @return {ListNode}
 */
var removeDuplicateNodes = function (head) {
    let left = head;
    while (left) {
        let right = left;
        while (right.next) {
            if (left.val === right.next.val) {
                right.next = right.next.next;
            } else {
                right = right.next;
            }
        }
        left = left.next;
    }

    return head;
};

/**
 * 测试用，利用数组生成单链表
 * @param {ListNode[]} arr 
 * @returns 
 */
function makeSinglyLinkedList(arr) {
    let head, pre = null;
    for (const n of arr) {
        const cur = { val: n, next: null };
        if (head == null) { head = cur; pre = head; } else {
            pre.next = cur;
            pre = cur;
        }
    }

    return head;
}