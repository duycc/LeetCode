/**
 * 递归
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function (root) {
    let result = [];

    function traversal(node) {
        if (node) {
            if (node.left) traversal(node.left);
            if (node.right) traversal(node.right);
            result.push(node.val);
        }
    }

    traversal(root);
    return result;
};


/**
 * 迭代 - 使用visited记录是否访问过右孩子
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function (root) {
    let result = [];

    let stack = [];
    let curNode = root;
    let visited = null;
    while (stack.length > 0 || curNode) {
        while (curNode) {
            stack.push(curNode);
            curNode = curNode.left;
        }

        curNode = stack.pop();
        if (curNode.right == null || curNode.right == visited) {
            // 无右孩子 | 右孩子已访问 -> 开始回退
            result.push(curNode.val);
            visited = curNode;
            curNode = null;
        } else {
            // 有右孩子，回栈，进入右孩子
            stack.push(curNode);
            curNode = curNode.right;
        }
    }

    return result;
};


/**
 * Morris
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function (root) {
    let result = [];

    let curNode = root;
    while (curNode) {
        if (curNode.left) {
            let mostRight = curNode.left;
            while (mostRight.right && mostRight.right != curNode) {
                mostRight = mostRight.right;
            }

            if (mostRight.right == null) {
                mostRight.right = curNode; // mark
                curNode = curNode.left;
                continue;
            } else {
                // 左子树遍历完毕
                mostRight.right = null; // resume
                _collectResult(curNode.left);
            }
        }
        curNode = curNode.right;
    }
    _collectResult(root);

    function _collectResult(head) {
        let tail = _reverseLinkedList(head); // reverse

        while (tail) {
            result.push(tail.val);
            tail = tail.right;
        }

        _reverseLinkedList(tail); // resume
    }

    function _reverseLinkedList(node) {
        let pre = null;
        while (node) {
            let nextNode = node.right;
            node.right = pre;
            pre = node;
            node = nextNode;
        }

        return pre; // new head
    }

    return result;
};
