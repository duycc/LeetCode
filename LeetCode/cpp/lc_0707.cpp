/**
 * @file     lc_0707.cpp
 * @brief    https://leetcode-cn.com/problems/design-linked-list/
 * @author   YongDu
 * @date     2021-09-08
 */
class MyLinkedList {
  struct LinkedNode {
    int val;
    LinkedNode *next;
    LinkedNode(int val) : val(val), next(nullptr) {}
  };

public:
  /** Initialize your data structure here. */
  MyLinkedList() {
    this->dummyNode_ = new LinkedNode(0);
    this->size_ = 0;
  }

  /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
  int get(int index) const {
    if (index < 0 || index >= this->size_) {
      return -1;
    }
    LinkedNode *curNode = this->dummyNode_->next;
    while (index--) {
      curNode = curNode->next;
    }
    return curNode->val;
  }

  /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the
   * first node of the linked list. */
  void addAtHead(int val) {
    LinkedNode *newNode = new LinkedNode(val);
    newNode->next = dummyNode_->next;
    dummyNode_->next = newNode;
    this->size_++;
    return;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    LinkedNode *curNode = dummyNode_;
    while (curNode->next) {
      curNode = curNode->next;
    }
    LinkedNode *newNode = new LinkedNode(val);
    curNode->next = newNode;
    this->size_++;
    return;
  }

  /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list,
   * the node will be appended to the end of linked list. If index is greater than the length, the node will not be
   * inserted. */
  void addAtIndex(int index, int val) {
    if (index > this->size_) {
      return;
    }

    LinkedNode *curNode = dummyNode_;
    while (index--) {
      curNode = curNode->next;
    }
    LinkedNode *newNode = new LinkedNode(val);
    newNode->next = curNode->next;
    curNode->next = newNode;
    this->size_++;
    return;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index < 0 || index >= this->size_) {
      return;
    }
    LinkedNode *curNode = dummyNode_;
    while (index--) {
      curNode = curNode->next;
    }
    LinkedNode *tmpNode = curNode->next;
    curNode->next = curNode->next->next;
    delete tmpNode;
    this->size_--;
    return;
  }

  void print() const {
    LinkedNode *curNode = dummyNode_->next;
    while (curNode) {
      std::cout << curNode->val << " -> ";
      curNode = curNode->next;
    }
    std::cout << "size: " << this->size_ << std::endl;
    return;
  }

private:
  int size_; // 元素容量
  LinkedNode *dummyNode_; // 虚拟头结点，方便操作
};
