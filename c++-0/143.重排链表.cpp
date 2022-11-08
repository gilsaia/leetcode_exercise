/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverse(ListNode *head) {
    ListNode *cur = head, *prev = nullptr;
    while (cur) {
      ListNode *tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    return prev;
  }
  void reorderList(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast->next) {
      fast = fast->next;
      if (fast->next) {
        fast = fast->next;
      } else {
        break;
      }
      slow = slow->next;
    }
    if (slow == head) {
      return;
    }
    fast = slow->next;
    slow->next = nullptr;
    fast = reverse(fast);
    slow = head;
    while (fast) {
      ListNode *tmp = slow->next, *tmp2 = fast->next;
      slow->next = fast;
      fast->next = tmp;
      slow = tmp;
      fast = tmp2;
    }
    return;
  }
};
// @lc code=end
