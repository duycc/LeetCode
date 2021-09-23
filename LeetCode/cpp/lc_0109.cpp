/**
 * @file     lc_0109.cpp
 * @brief    https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 * @author   YongDu
 * @date     2021-09-10
 */
/**
 * @file     sortedListToBST.cpp
 * @brief
 * @author   DuYong
 * @date     2021-03-08
 */

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    return buildBST(head, nullptr);
    // another: list -> vector -> BST
  }

  TreeNode *buildBST(ListNode *head, ListNode *tail) {
    if (head == tail)
      return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != tail && fast->next != tail) {
      slow = slow->next;
      fast = fast->next->next;
    }

    TreeNode *root = new TreeNode(slow->val);
    root->left = buildBST(head, slow);
    root->right = buildBST(slow->next, tail);

    return root;
  }
};
