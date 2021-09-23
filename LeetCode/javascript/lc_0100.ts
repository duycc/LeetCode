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


// 递归 DFS

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    if (p == null && q == null) {
        return true;
    }
    if (p && q) {
        if (p.val == q.val) {
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
        return false;
    }
    return false;
};

// 迭代 DFS
function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    let isSame = true;
    let stack: [TreeNode, TreeNode][] = [];
    stack.push([p, q]);
    while (isSame && stack.length > 0) {
        const [p, q] = stack.pop();
        if (p && q) {
            if (p.val == q.val) {
                stack.push([p.left, q.left]);
                stack.push([p.right, q.right]);
            } else {
                isSame = false;
            }
        } else if (p !== q) {
            isSame = false;
        }
    }
    return isSame;
};
