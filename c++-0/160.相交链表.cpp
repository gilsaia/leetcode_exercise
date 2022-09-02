/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include <algorithm>
using namespace std;
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    int lena = 0, lenb = 0;
    while (a) {
      ++lena;
      a = a->next;
    }
    while (b) {
      ++lenb;
      b = b->next;
    }
    a = headA;
    b = headB;
    if (lena < lenb) {
      swap(a, b);
      swap(lena, lenb);
    }
    while (lena > lenb) {
      a = a->next;
      --lena;
    }
    while (a && b && a != b) {
      a = a->next;
      b = b->next;
    }
    if (a && a == b) {
      return a;
    }
    return nullptr;
  }
};
// @lc code=end
