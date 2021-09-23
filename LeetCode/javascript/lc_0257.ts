/**
 * @file     binaryTreePaths.ts
 * @brief    https://leetcode-cn.com/problems/binary-tree-paths/submissions/
 * @author   Zhu
 * @date     2021-07-31 16:22
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

// DFS - 递归
function binaryTreePaths(root: TreeNode | null): string[] {
    const result: string[] = [];

    function traversal(node: TreeNode, path: TreeNode['val'][]) {
        const _path = path.concat(node.val);
        if (node.left == null && node.right == null) {
            result.push(_path.join("->"));
        }
        if (node.left) traversal(node.left, _path);
        if (node.right) traversal(node.right, _path);
    }
    root && traversal(root, []);

    return result;
};

// DFS - 迭代 模拟 递归
function binaryTreePaths(root: TreeNode | null): string[] {
    const result: string[] = [];

    const stack: [TreeNode, TreeNode['val'][]][] = [];
    root && stack.push([root, []]);
    while (stack.length > 0) {
        const [node, path] = stack.pop();
        const _path = path.concat(node.val);
        if (node.left == null && node.right == null) {
            result.push(_path.join("->"));
        }
        if (node.left) stack.push([node.left, _path]);
        if (node.right) stack.push([node.right, _path]);
    }

    return result;
};

// BFS
function binaryTreePaths(root: TreeNode | null): string[] {
    const result: string[] = [];

    const queue: [TreeNode, TreeNode['val'][]][] = [];
    root && queue.push([root, []]);
    while (queue.length > 0) {
        const [node, path] = queue.shift();
        const _path = path.concat(node.val);
        if (node.left == null && node.right == null) {
            result.push(_path.join("->"));
        }
        if (node.left) queue.push([node.left, _path]);
        if (node.right) queue.push([node.right, _path]);
    }

    return result;
};
