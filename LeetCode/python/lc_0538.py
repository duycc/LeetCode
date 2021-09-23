"""
 * @file     lc_0538.py
 * @brief    https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 * @author   YongDu
 * @date     2021-09-09
"""
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        def buildTree(root):
            if not root:
                return None
            buildTree(root.right)
            root.val += self.preVal
            self.preVal = root.val
            buildTree(root.left)

        self.preVal = 0
        buildTree(root)
        return root
