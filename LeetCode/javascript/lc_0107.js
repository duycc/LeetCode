/**
 * @file     levelOrderBottom.js
 * @brief    https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 * @author   Zhu
 * @date     2021-07-30 12:25
 */

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function (root) {
    let result = [];

    let queue = [];
    root && queue.push(root);
    while (queue.length > 0) {
        let levelSize = queue.length;
        let levelResult = [];
        while (levelSize-- > 0) {
            const cur = queue.shift();
            levelResult.push(cur.val);
            if (cur.left) queue.push(cur.left);
            if (cur.right) queue.push(cur.right);
        }
        result.unshift(levelResult);
    }

    return result;
};
