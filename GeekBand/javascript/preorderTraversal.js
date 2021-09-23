/**
 * 二叉树节点
 */
function TreeNode(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
}

/**
 * 从数组生成二叉树
 */
function makeBinaryTree(arr) {
    const len = arr.length;
    const createNode = (i) => {
        if (i < len && arr[i] !== null) {
            return new TreeNode(arr[i], createNode(2 * i + 1), createNode(2 * i + 2));
        }
        return null;
    };

    return createNode(0);
}

/**
 * 前序遍历 - 递归
 * @param {TreeNode} root 根节点
 * @returns {number[]}
 */
var preorderTraversal = function (root) {
    let result = [];

    function nodeTraversal(node) {
        if (node) {
            result.push(node.val);
            if (node.left) { nodeTraversal(node.left); }
            if (node.right) { nodeTraversal(node.right); }
        }
    }
    nodeTraversal(root);

    return result;
};

/**
 * 前序遍历 - 迭代 - 标准模拟解法
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function (root) {
    let result = [];

    let stack = [];
    root && stack.push(root);

    while (stack.length > 0) {
        let node = stack.pop();
        result.push(node.val);
        if (node.right) stack.push(node.right);
        if (node.left) stack.push(node.left);
    }

    return result;
};

/**
 * 前序遍历 - 迭代 - 前中后通用解法
 * @param {TreeNode} root 根节点
 * @returns {number[]}
 */
var preorderTraversal = function (root) {
    let result = [];

    let stack = [];

    let node = root;
    while (node || stack.length > 0) {
        while (node) {
            result.push(node.val);
            stack.push(node.right);
            node = node.left;
        }
        node = stack.pop();
    }

    return result;
};

/**
 * Morris 遍历 - 找到cur的左子树的最右节点，使其right指向cur
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function (root) {
    let result = [];

    let curNode = root;
    while (curNode) {
        if (curNode.left) {
            let mostRight = curNode.left;
            while (mostRight.right && mostRight.right != curNode) {
                mostRight = mostRight.right;
            }

            if (mostRight.right == null) {
                mostRight.right = curNode;
                result.push(curNode.val);
                curNode = curNode.left;
                continue;
            } else {
                mostRight.right = null;
            }
        } else {
            result.push(curNode.val);
        }

        curNode = curNode.right;
    }

    return result;
};
