// 递归
function isValidBST(root: TreeNode | null): boolean {

    function isValid(node: TreeNode | null, lower: number, higher: number): boolean {
        if (node == null) return true;
        if (lower < node.val && higher > node.val) {
            return isValid(node.left, lower, node.val) && isValid(node.right, node.val, higher);
        }
        return false;
    }

    return isValid(root, -Infinity, Infinity);
};

// 中序遍历，就是左中右的顺序
function isValidBST(root: TreeNode | null): boolean {

    let valid = true;

    let lastValue = -Infinity;
    function traversal(node: TreeNode) {
        if (node) {
            valid && traversal(node.left);
            if (lastValue < node.val) {
                lastValue = node.val;
            } else {
                valid = false;
            }
            valid && traversal(node.right);
        }
    }

    root && traversal(root);

    return valid;
};

// 迭代版中序遍历
function isValidBST(root: TreeNode | null): boolean {
    let valid = true;

    let cur = root;
    let stack = [];
    let lastValue = -Infinity;
    while (valid && (cur || stack.length > 0)) {
        while (cur) {
            stack.push(cur);
            cur = cur.left;
        }
        cur = stack.pop();
        if (lastValue < cur.val) lastValue = cur.val;
        else valid = false;
        cur = cur.right;
    }

    return valid;
};