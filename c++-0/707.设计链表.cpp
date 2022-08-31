/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
struct ListNodeT {
  int val;
  ListNodeT *next, *prev;
  ListNodeT() : val(0), next(nullptr), prev(nullptr) {}
  ListNodeT(int x) : val(x), next(nullptr), prev(nullptr) {}
  ListNodeT(int x, ListNodeT *next) : val(x), next(next), prev(nullptr) {}
  ListNodeT(int x, ListNodeT *next, ListNodeT *prev)
      : val(x), next(next), prev(prev) {}
};
class MyLinkedList {
public:
  MyLinkedList() {
    length = 0;
    head = new ListNodeT();
    tail = new ListNodeT();
    head->next = tail;
    tail->prev = head;
  }

  int get(int index) {
    if (index >= length || index < 0) {
      return -1;
    }
    ListNodeT *curr = head;
    ++index;
    while (index) {
      curr = curr->next;
      --index;
    }
    return curr->val;
  }

  void addAtHead(int val) {
    ListNodeT *curr = new ListNodeT(val, head->next, head);
    head->next->prev = curr;
    head->next = curr;
    ++length;
  }

  void addAtTail(int val) {
    ListNodeT *curr = new ListNodeT(val, tail, tail->prev);
    tail->prev->next = curr;
    tail->prev = curr;
    ++length;
  }

  void addAtIndex(int index, int val) {
    if (index > length) {
      return;
    }
    if (index < 0) {
      index = 0;
    }
    ListNodeT *curr = head;
    while (index) {
      curr = curr->next;
      --index;
    }
    ListNodeT *insert = new ListNodeT(val, curr->next, curr);
    curr->next->prev = insert;
    curr->next = insert;
    ++length;
  }

  void deleteAtIndex(int index) {
    if (index >= length || index < 0) {
      return;
    }
    ListNodeT *curr = head;
    while (index) {
      curr = curr->next;
      --index;
    }
    curr->next = curr->next->next;
    curr->next->prev = curr;
    --length;
  }

private:
  ListNodeT *head, *tail;
  int length;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
