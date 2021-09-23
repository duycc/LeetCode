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
 * @return {number[][]}
 */
var levelOrder = function (root) {
    const result = [];

    const queue = [];
    root && queue.push(root);
    while (queue.length > 0) {
        const levelResult = [];
        const levelLength = queue.length;
        for (let i = 0; i < levelLength; i++) {
            const cur = queue.shift();
            levelResult.push(cur.val);
            if (cur.left) queue.push(cur.left);
            if (cur.right) queue.push(cur.right);
        }
        result.push(levelResult);
    }

    return result;
};

/**
 * 递归/DFS
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
    const result = [];

    function traversal(node, level) {
        result[level] = result[level] ?? [];
        result[level].push(node.val);
        if (node.left) traversal(node.left, level + 1);
        if (node.right) traversal(node.right, level + 1);
    }

    root && traversal(root, 0);
    return result;
};
