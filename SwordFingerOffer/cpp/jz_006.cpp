/**
 * @file     jz_006.cpp
 * @brief    https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 * @author   YongDu
 * @date     2021-10-16
 */

//===------------------------- [递归版] ------------------------------------===//
//
//===----------------------------------------------------------------------===//

class Solution {
public:
  vector<int> reversePrint(ListNode *head) {
    if (head == NULL) {
      return vector<int>();
    }
    reversePrint(head->next);
    result.emplace_back(head->val);
    return result;
  }

private:
  vector<int> result;
};

//===------------------------- [迭代版] ------------------------------------===//
//
//===----------------------------------------------------------------------===//
class Solution {
public:
  vector<int> reversePrint(ListNode *head) {
    vector<int> result;
    while (head) {
      result.emplace_back(head->val);
      head = head->next;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
