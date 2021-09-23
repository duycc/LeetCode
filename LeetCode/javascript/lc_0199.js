/**
 * @file     rightSideView.js
 * @brief    https://leetcode-cn.com/problems/binary-tree-right-side-view/submissions/
 * @author   Zhu
 * @date     2021-07-29 22:02
 */


/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * BFS
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function (root) {
    let result = [];

    let queue = [];
    root && queue.push(root);
    while (queue.length > 0) {
        const levelLength = queue.length;
        let cur;
        for (let i = 0; i < levelLength; i++) {
            cur = queue.shift();
            if (cur.left) queue.push(cur.left);
            if (cur.right) queue.push(cur.right);
        }
        result.push(cur.val);
    }

    return result;
};

/**
 * 递归
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function (root) {
    let result = [];

    function traversal(node, level) {
        result[level] = node.val; // 同一层内，永远是先左后右，也就是层序，最后一个就是同层内最右的
        if (node.left) traversal(node.left, level + 1);
        if (node.right) traversal(node.right, level + 1);
    }

    root && traversal(root, 0);
    return result;
};
