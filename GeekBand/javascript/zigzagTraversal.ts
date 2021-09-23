function zigzagLevelOrder(root: TreeNode | null): number[][] {
    const result: number[][] = [];

    let left2Right = true;
    const deque: TreeNode[] = [];
    root && deque.push(root);
    while (deque.length) {
        let levelSize = deque.length;
        let levelVals: number[] = [];
        while (levelSize--) {
            let cur: TreeNode;
            if (left2Right) {
                cur = deque.shift();
                if (cur.left) deque.push(cur.left);
                if (cur.right) deque.push(cur.right);
            } else {
                cur = deque.pop();
                if (cur.right) deque.unshift(cur.right);
                if (cur.left) deque.unshift(cur.left);
            }
            levelVals.push(cur.val);
        }
        left2Right = !left2Right;
        result.push(levelVals);
    }

    return result;
};