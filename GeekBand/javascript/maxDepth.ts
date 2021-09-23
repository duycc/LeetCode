/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

// DFS 递归
function maxDepth(root: TreeNode | null): number {
    function getHeight(node: TreeNode | null): number {
        if (node == null) return 0;
        const leftHeight = getHeight(node.left);
        const rightHeight = getHeight(node.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    return getHeight(root);
};

// BFS
function maxDepth(root: TreeNode | null): number {
    let queue = [];

    let level = 0;
    root && queue.push(root);
    while (queue.length) {
        let size = queue.length;
        level++;
        while (size--) {
            const cur = queue.shift();
            if (cur.left) queue.push(cur.left);
            if (cur.right) queue.push(cur.right);
        }
    }

    return level;
};