/**
 * 递归
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    let result = [];

    function traversal(node) {
        if (node) {
            if (node.left) traversal(node.left);
            result.push(node.val);
            if (node.right) traversal(node.right);
        }
    }

    traversal(root);
    return result;
};

/**
 * 迭代
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    let result = [];

    let stack = [];
    let cur = root;
    while (stack.length > 0 || cur != null) {
        while (cur) {
            stack.push(cur);
            cur = cur.left;
        }
        cur = stack.pop();
        result.push(cur.val);
        cur = cur.right;
    }

    return result;
};


/**
 * Morris - 精简
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
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
                curNode = curNode.left;
                continue;
            }

            mostRight.right = null;
        }
        result.push(curNode.val);
        curNode = curNode.right;
    }

    return result;
};

/**
 * Morris - 啰嗦
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
    let result = [];

    let curNode = root;
    while (curNode) {
        if (curNode.left) {
            let mostRight = curNode.left;
            let noRightChild = mostRight.right == null; // 无右孩
            let hasRightChild = !noRightChild;
            let rightChildBackToRoot = mostRight.right == curNode; // 回根节点
            let rightChildNotBackToRoot = !rightChildBackToRoot;
            while (hasRightChild && rightChildNotBackToRoot) {
                mostRight = mostRight.right;
            }
            if (noRightChild) {
                mostRight.right = curNode;
                curNode = curNode.left;
            } else if (rightChildBackToRoot) {
                mostRight.right = null;
                result.push(curNode.val);
                curNode = curNode.right;
            }
        } else {
            result.push(curNode.val);
            curNode = curNode.right;
        }
    }

    return result;
};