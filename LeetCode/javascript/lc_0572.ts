// 暴力递归，每个节点都算一遍
function isSubtree(root: TreeNode | null, subRoot: TreeNode | null): boolean {

    function compare(node: TreeNode | null, subNode: TreeNode | null) {
        if (node == null && subNode == null) {
            return true;
        }
        if (node && subNode) {
            if (node.val === subNode.val) {
                return compare(node.left, subNode.left) && compare(node.right, subNode.right);
            }
            return false;
        }
        return false;
    }

    let isSame = false;
    function traversal(node: TreeNode) {
        if (compare(node, subRoot)) {
            isSame = true;
        }
        else {
            if (node.left) traversal(node.left);
            if (node.right) traversal(node.right);
        }
    }

    root && traversal(root);

    return isSame;
};
