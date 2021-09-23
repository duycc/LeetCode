/**
 * @file     isBalanced.ts
 * @brief    https://leetcode-cn.com/problems/balanced-binary-tree/submissions/
 * @author   Zhu
 * @date     2021-07-31 13:09
 */


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
 * 自底向上，理解递归是一个触底反弹的过程
 */
function isBalanced(root: TreeNode | null): boolean {

    function getTreeHeight(node: TreeNode | null): number {
        if (node) {
            const leftHeight = getTreeHeight(node.left);
            const rightHeight = getTreeHeight(node.right);
            if (leftHeight == -1) return -1;
            if (rightHeight == -1) return -1;
            if (Math.abs(leftHeight - rightHeight) > 1) return -1;
            return 1 + Math.max(leftHeight, rightHeight);
        }
        return 0;
    }

    return getTreeHeight(root) !== -1;
};
