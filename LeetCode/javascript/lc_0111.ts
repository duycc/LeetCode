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

/**
 * BFS：找到第一个叶子节点
 */
function minDepth(root: TreeNode | null): number {

    let queue = [];
    root && queue.push(root);
    let level = 0;
    while (queue.length) {
        level++;
        let size = queue.length;
        while (size--) {
            const cur = queue.shift();
            if (cur.left == null && cur.right == null) { return level; }
            if (cur.left) queue.push(cur.left);
            if (cur.right) queue.push(cur.right);
        }
    }
    return level;
};

/**
 * DFS
 */
function minDepth(root: TreeNode | null): number {
    if (root == null) return 0;
    const leftDepth = minDepth(root.left);
    const rightDepth = minDepth(root.right);
    return ((leftDepth && rightDepth) ? Math.min(leftDepth, rightDepth) : rightDepth + leftDepth) + 1;
    // return (leftDepth == 0 ? rightDepth : rightDepth == 0 ? leftDepth : Math.min(leftDepth, rightDepth)) + 1;
};
