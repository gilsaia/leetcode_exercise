/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (!head) {
      return false;
    }
    ListNode *fast = head, *slow = head;
    while (fast->next) {
      fast = fast->next;
      if (fast->next) {
        fast = fast->next;
      } else {
        return false;
      }
      slow = slow->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
